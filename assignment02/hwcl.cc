//
//  main.c
//  CS_2450
//  Assignment 2
//  Created by Nick Burkett on 10/15/20.
//

#include <stdio.h>

void printTriangle(int n){
    
    //Here I will check if user input is less than 1.
    if (n < 1) {
        return;
    }
    
   else if(n <= 3){
           //Declare variables for while loops.
           int i = 1;
           int j = 1;

           //Start of the outer loop.
           while(i <= n){

                   //Start of the inner loop.
                   while(j <= n){
                    
                       //Fisrt conditional... check if I need to print
                       //a space.
                       if(j < (n - i + 1)){
                               printf(" ");
                       }

                       //If if is not caught by the above condtitional
                       //Then it should need to print a "+".
                       else{
                               printf("+");
                       }

                       //Increment j.
                       j++;

                   }

                   //Print a line break to begin a new row.
                   printf("\n");
                   j = 1;
                   //Increment i.
                   i++;
           }

   }
   
   //Now we know that n should be greater than 3.
   else{
       
       //Declare the variables for the loops.
       int i = 1;
       int j = 1;
       
       //Here we start the outer loop.
       while(i < n){

               //Start of the inner loop.
               while(j <= n){
                
                   //Fisrt conditional... check if I need to print
                   //a space.
                   if(j < (n - i + 1)){
                           printf(" ");
                   }

                   //If if is not caught by the above condtitional
                   //Then I need to either print a "-" or a "+".
                   else{
                       
                       //If i <= 2 then all we need to do is print "+".
                       if (i <= 2){
                           printf("+");
                       }
                       
                       //If i is greater than 2 we need to check where to print a "-" and a "+".
                       else{
                           
                           //Checks to see if j is is on the bounds in the loop.
                           if(j == (n - i + 1) || j == n){
                               printf("+");
                           }
                           
                           // If its not sitting on a bound then it must be inbetween
                           //the bounds and must be a "-".
                           else{
                               printf("-");
                           }
                       }
                   }

                   //Increment j.
                   j++;

               }

            //Print a line break to begin a new row.
            printf("\n");
            j = 1;
            //Increment i.
            i++;
           
            //Here I check to see if we are on the last row after
            //incrementing i... If it is, then we just need the last
            //row to be "+".
            if (i == n){
                int x = 0;
                while(x < n){
                    printf("+");
                    x++;
                }
                printf("\n");
            }
           
       }
       
   }
           
}

void printRectangle(int x, int y){
    
    //Here I check to see if either of my values are less than 1.
    if(x < 1 || y < 1){
        return;
    }
    
    //Otherwise go ahead and start the printing process.
    else{
        
        //Start of the outer loop.
        for(int i = 1; i <= y; i ++){
            
            //Start of the inner loop.
            for(int j = 1; j <= x; j++){
                
                //Here I check to see if we are in
                //the first row or the last row
                //if so, print a "+".
                if(i == 1 || i == y ){
                    printf("+");
                }
                else{
                    
                    //Here I check if we are in the first or
                    //last column... if so, print a "+".
                    if(j == 1 || j == x){
                        printf("+");
                    }
                    
                    //Otherwise we are in the middle portion of our
                    //rectangle and need to just print a "-"
                    else{
                        printf("-");
                    }
                }
            }
            
            //This is a line break to start a new row.
            printf("\n");
            }
        
        }
    return;
    }
    
void printFormat(int x, int y, int z){
    
    //initialize a counter variable.
    int helperVar1 = 1;
    
    if((x < 1 && y < 1) || (x < 1 && z < 2)){
        return;
        
    }
    
    else if(y < 1 && z < 2){
        for(int i = 1; i <= x; i++){
            if(i == x){
                printf("%-d\n", i);
                return;
            }
            else{
                printf("%-d\t", i);
            }
        }
        return;
    }
    
    //Conditional to see if x is less than 1.
    if(x < 1){
        return;
    }
    
    //Check to see if our column value is less than 1...
    //if so, print everythig on one line.
    else if(y < 1){
        
        //Start of the loop.
        for(int i = 1; i <= x; i++){
            if((helperVar1 % z) == 0){
                //printf("");
            }
            
            //Here I check if our counter variable is
            //less than our end value...If so, print the formatted
            //string with a tab at the end.
            else if (helperVar1 < x){

                    if((helperVar1 + 1) == x && ((helperVar1 + 1) % z) == 0){
                        printf("%-d\n", helperVar1);
                        return;
                    }
                    else{
                        printf("%-d\t", helperVar1);
                    }

            }
            
            //Check to see if our counter variable is equal to
            //our end value...If so, print the formated string with a newline
            //at the end instead of a tab and return because we are done.
            else if(helperVar1 == x){
                if((helperVar1 % z) == 0){
                    printf("\n");
                }
                else{
                    printf("%-d\n", helperVar1);
                }
               return;
            }
            
            helperVar1 ++;
        }
        

    }
    
    //Here I check to see if our multiple variable is less than 2...
    //if so, dont exclude anything.
    else if(z < 2){
        
        //start of outer loop.
        while(helperVar1 <= x){
            
            //Start of inner loop.
            for(int i = 1; i <= y; i++){
                
                //Here I check if our counter variable is
                //less than our end value...If so, print the formatted
                //string with a tab at the end.
                if (helperVar1 < x){
                    //Print the formatted variable.
                    if(i == y){
                        printf("%-d", helperVar1);
                    }
                    else{
                        printf("%-d\t", helperVar1);
                    }
                }
                
                
                //Check to see if our counter variable is equal to
                //our end value...If so, print the formated string with a newline
                //at the end instead of a tab and return because we are done.
                else if(helperVar1 == x){
                   printf("%-d\n", helperVar1);
                   return;
                    
                }
                
                
                helperVar1 ++;
            }
            
            //Print a line break to start a new row.
            printf("\n");
        }
    }
    

    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //If we dont get caught up in the above conditionals then
    //we have vaild inputs and need to print the formatted table normally.
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    else{
        //Start of outer loop
        while(helperVar1 <= x){
            
            //Start of the inner loop.
            for(int i = 1; i <= y; i++){
                
                //Here I check if our counter variable is
                //less than our end value...If so, print the formatted
                //string with a tab at the end.
                if(helperVar1 < (x - 1)){
                    if((helperVar1 % z) != 0){
                        if(i == y){
                            printf("%-d", helperVar1);
                        }
                        else{
                            printf("%-d\t", helperVar1);
                        }
                        
                    }
                    else{
                        i--;
                    }
                    
                    
                }
                else if (helperVar1 == (x-1)){
                    
                    if(((helperVar1) % z) != 0){
                        
                        if(i == y){
                            printf("%d", helperVar1);
                        }
                        else{
                            if(((helperVar1 + 1) % z) == 0){
                                printf("%d\n", helperVar1);
                                return;
                            }
                            else{
                                printf("%d\t", helperVar1);
                            }
                        }
                    }
                    else{
                        i--;
                        
                    }
                    
                }
                
                //Check to see if our counter variable is equal to
                //our end value...If so, print the formated string with a newline
                //at the end instead of a tab and return because we are done.
                else{
                    
                    //Here we check to see we have a multiple of z...If so,
                    //I need to either print a line break and return or
                    //print the last number with a new line at the end and return.
                    if((helperVar1 % z) != 0){
                        printf("%-d\n", helperVar1);
                    }
                    
                    return;
                }
                helperVar1 ++;
            }
            
            //Print a line break to start a new row.
            
            printf("\n");
            
            
        }
    }
}

