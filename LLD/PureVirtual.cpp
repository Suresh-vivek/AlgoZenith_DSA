#include <bits/stdc++.h>
using namespace std;

class Database{
        public:
         virtual void Read()=0;

         virtual void Write() =0;

         virtual void Query() =0;


};

class MySQl : public Database{
        public:

};

class postgreSql : public Database{
        public: 
}; 