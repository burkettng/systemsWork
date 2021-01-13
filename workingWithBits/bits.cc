//
//  main.c
//  CS_2450
//  Assignment 2
//  Created by Nick Burkett on 10/15/20.
//

#include <stdio.h>

void print3dPoint(int var1){

    //Mask for the last 10 bits.
    int maskA = 0x3FF00000;
    
    //Mask for the middle 10 bits.
    int maskB = 0xFFC00;
    
    //Mask for the first 10 bits.
    int maskC = 0x3FF;
    
    //Here I set helperVarA to the result of var1 & maskA.
    int helperVarA = (var1 & maskA);
    
    //Then I right shift the variable 20 bits to calculate properly.
    helperVarA = helperVarA >> 20;
    
    //Here I set helperVarB to the result of var1 & maskB.
    int helperVarB = (var1 & maskB);
    
    //Then I right shift the variable 10 bits to calculate properly.
    helperVarB = helperVarB >> 10;
    
    //Here I set helperVarC to the result of var1 & maskC.
    //Also note: I do not need to shift anything because we are already
    //in the farthest right 10 bits.
    int helperVarC = (var1 & maskC);
    
    //Finally I print the formatted string accordling to the instructions.
    printf("(%d, %d, %d)\n", helperVarA, helperVarB, helperVarC);
    
    
}

int swapBytes(int var1){
    
    //Mask for bits 31 - 24.
    int maskA = 0xFF000000;
    
    //Mask for bits 23-16.
    int maskB = 0xFF0000;
    
    //Mask for bits 15 - 8.
    int maskC = 0xFF00;
    
    //Mask for bits 7 - 0.
    int maskD = 0xFF;
    
    //Here we "grab" each byte within the number
    //and store that number in the following variable.
    //I then either right or left shit according to position
    //by 8 bits.
    int helperA = var1 & maskA;
    helperA = helperA >> 8;
    
    int helperB = var1 & maskB;
    helperB = helperB << 8;
    
    int helperC = var1 & maskC;
    helperC = helperC >> 8;
    
    int helperD = var1 & maskD;
    helperD = helperD << 8;
    
    //After spliting up the bytes and shifting them around
    //I am ready to add everything back together.
    int finalVar = helperA + helperB + helperC + helperD;
    
    //Finally I print the new number in hexadecimal
    //printf("%.8X\n", finalVar);
    return finalVar;
    
}

int countGroups(int var1){

	//Initialize the variable representing the group number. 
    int groupNum = 0;
    
    //Here I start stepping through the 32-bit number. 
    for(int i = 0; i < 32; i ++){
        
        //Conditional to check if we have a 1 at the current position. 
        if((var1 & (1 << i)) != 0){
            
            //Increment the groupings of 1's. 
            groupNum ++;
            
            //Set helper to 1, so I can enter the while loop. 
            int helper = 1;
            
            //Keep track of how many bits AHEAD we look. 
            int extra = 1;
            
            //Here we need to check if the following bits are 1's as well. 
            while(helper == 1){
                
                //Make sure I dont go out of bounds. 
                if((i + extra) > 31){
                    helper = 0;
                }
                
                //Check if the next bit is a 1. If it is add one to 
                //extra and continue to check. 
                else if(var1 & (1 << (i + extra)) ){
                    
                    extra ++;
                }
                
                //Once I hit a 0 I need to get out of the "grouping".
                else{
                    helper = 0;
                }
                
            }
            
            //Once we have gotten out of the "grouping" I need to
            //update i, as I have looked ahead a minimum of i + 1 bits.
            i += extra;
            
        }
    }
    
    //printf("%d\n", groupNum);
    
    //Return the amount of groups. 
    return groupNum;
}
