#include "BitOperation.h"

BitOperation::operation(int a,int b,char operation){
     if(operation=='='){
            if(a==1&&b==1){
                return 1;
            }
            else if (a==1&&b==0){
                return 0;
            }
            else if (a==0&&b==1){
                return 0;
            }
            else if (a==0&&b==0){
                return 1;
            }
        }
        else if(operation=='>'){
            if(a==1&&b==1){
                return 1;
            }
            else if(a==1&&b==0){
                return 0;
            }
            else if(a==0&&b==1){
                return 1;
            }
            else if(a==0&&b==0){
                return 1;
            }
        }
        else if (operation=='^'){
            return (a&b);
        }
        else if (operation=='|'){
            return (a|b);
        }
        else if (operation=='~'){
            return (!a);
        }
}
