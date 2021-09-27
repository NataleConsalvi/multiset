#ifndef MULTISET_H
#define MULTISET_H

#include <unordered_map>
#include <sstream>

void debug_stamp(std::string s){
    std::cout << "DEBUG: " << s << "." << std::endl;
}

template <typename T>
class MultiSet{

    std::unordered_map<T,int> umap;

    public:

        /** Adds one instance of element el to the multiset
         
            MUST run in O(1)       
        */
        void add(const T el){
            std::stringstream s;
            s << "adding " << el;
            debug_stamp(s.str());
            if(umap.count(el) == 1){
                umap[el]++;
            }else{
                umap[el] = 1;
            }
        }

        /**
        *  RETURN the multiplicity of element el in the multiset
                
            - If no instance of el is present, return 0.

            MUST run in O(1)                 
        */   
        int get(const T el) const{
            if(umap.count(el) == 1){
                return umap.at(el);
            }else{
                return 0;
            }
        }

        /** Removes n instances of element el from the multiset (that is, reduces el multiplicity by n)
                 
                If n is negative, throws std::invalid_argument           
                If n represents a multiplicity bigger than el current multiplicity, throws std::out_of_range
                
                NOTE: multiset multiplicities are never negative
                MUST run in O(1)
        */
        void removen(const T el, const int n){
            std::stringstream s;
            s << "removing " << el << ", " << n;
            debug_stamp(s.str());
            if(n < 0){
                throw std::invalid_argument(std::string("n is negative! n = " + std::to_string(n)));
            }else{
                if(umap.count(el) == 1){
                    if(umap.at(el) < n){
                        throw std::out_of_range(std::string("n is greather than el current multiplicity (el = " + std::to_string(umap.at(el)) + ")"));
                    }else{
                        umap[el] = umap[el] - n;
                    }
                }else{

                }

            }
        }

        std::string as_string(){
            std::stringstream s;
            s << "{\n";
            for(std::pair<T,int>elem:umap){
                s << "\t{" << elem.first << ", " << elem.second << "}\n";
            }
            s << "}";
            return s.str();          
        }


        /**
            * RETURN the number of elements within the multiset (sum of all multiplicites)
            *
            * MUST run in O(k) where k is the number of keys
        */
        int size() const{
            debug_stamp(std::string("calculating size of multiset, size = "));
            int ret = 0;
            for(std::pair<T,int>elem:umap){
                ret += elem.second;
            }
            return ret;
        }



     




};

#endif //MULTISET_H