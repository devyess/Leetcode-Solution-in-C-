class Solution {
    enum class FixType {
        REPLACE = 0,
        INSERT = 1,
        DELETE = 2
    };

    struct Problems {
        int length = 0;
        int missing_chars = 0;
        std::vector< int > repeats;
        
        bool empty() const {
            return ( length >= 6 && length <= 20 ) && !missing_chars && repeats.empty();
        }
        
        bool apply( FixType fix_type ) {
            if( length <= 6 && fix_type == FixType::DELETE ) {
                return false;
            }
            if( length >= 20 && fix_type == FixType::INSERT ) {
                return false;
            }
            
            // Insert and Delete affects the length
            bool applied = fix_type != FixType::REPLACE;
            if( missing_chars && fix_type != FixType::DELETE ) {
                missing_chars--;
                applied = true;
            }
            
            int repeat = 0;
            if( !repeats.empty() ) {
                repeat = repeats.back();
                repeats.pop_back();
                applied = true;
            } 
            switch( fix_type ) {
                case FixType::REPLACE:
                    // [R,R,#,...]
                    repeat -= 3;
                    break;
                case FixType::INSERT:
                    // [R,R,#,R...]
                    repeat -= 2;
                    length += 1;
                    break;
                case FixType::DELETE:
                    // [R,R,...]
                    repeat -= 1;
                    length -= 1;
                    break;
            }
            if( repeat >= 3 ) {
                repeats.push_back( repeat );
            }
            return applied;
        }
    };
    
public:
    int strongPasswordChecker( const std::string & s ) {
        std::queue< Problems > queue( { getProblems( s ) } );
        int level = 0;
        
        while( !queue.empty() ) {
            int level_size = queue.size();
            for( int i = 0; i < level_size; i++ ) {
                Problems problems = queue.front();
                queue.pop();
                
                if( problems.empty() ) {
                    return level;
                }

                for( const FixType & fix_type : { FixType::REPLACE, FixType::INSERT, FixType::DELETE } ) {
                    Problems fixed = problems;
                    if( fixed.apply( fix_type ) ) {
                        queue.push( fixed );
                    }
                }
            }
            level++;
        }
        return level;
    }
    
private:
    Problems getProblems( const std::string & s ) {
        Problems problems;
        int digit = 1;
        int lower = 1;
        int upper = 1;
        for( int i = 0; i < s.size(); ) {
            int pos = i;
            while( i < s.size() && s[ pos ] == s[ i ] ) {
                i++;
            }
            int length = i - pos;
            if( length >= 3 ) {
                problems.repeats.push_back( length );
            }
            
            if( std::isdigit( s[ pos ] ) ) {
                digit = 0;
            }
            else if( std::islower( s[ pos ] ) ) {
                lower = 0;
            }
            else if( std::isupper( s[ pos ] ) ) {
                upper = 0;
            }
            problems.length += length;
        }
        problems.missing_chars = digit + lower + upper;
        return problems;
    }
};