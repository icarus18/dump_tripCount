/*
Sam S.
1/26/2021
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;



int main() {
    
    /*Enter float values between 1.000 and 3.000.This program identifies 
    a scenario where each value represents the weight of a bag, and a worker 
    can only carry a max of 3 lbs at a time.With n number of bags present 
    in an array weighted the value entered x, how man trips would it take 
    for him or her to carry all bags to a dumpster.*/
    
    //Enter values
    printf("Enter a number 1.00 - 3.00 <0 to halt> ");
    float e_arr;
    vector <float> arr;
    do {
        printf("->: "); 
        cin >> e_arr; 
        if (e_arr>0.000) {
            arr.push_back(e_arr);  //values stored in a vector array
        }
    
    
    } while (e_arr != 0);
  
    
    float tmp = 0;
    int count = 0;
    int county = 0;
    
    int size = arr.size();
    
    //array printed out
    printf("Unsorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%.3f ", arr[i]);

    }

    //Array is sorted from smallest value to largest.Iterates until all values are set from small to big.
    int run = 0;
    do {
        for (int i = 0; i < size - 1; i++) {
            run = 0;
            for (int j = i + 1; j < size; j++) {
                float temp = 0.0;
               
                if (arr[i] > arr[j])
                {
                    run++;
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
                i++;
            }
        }
    } while (run !=0);

  
    //printed array is now sorted
    printf("\nSorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%.3f ", arr[i]);

    }
    
    
    //Algorithm Counts the number of tries, when max weight is reached it 
    //exits inner do-while and proceeds to count the trip.
    int b = 0;
    while(size>0){

        tmp = 0;
        county = 0;
        do {
            if (b < arr.size()) {
                tmp += arr[b];         //values of each element are stored to compare in a temporary variable
                b++;
            }
            if (tmp < 3) {
                county++;               // county variable counts the number of elements that have already been accounted for.
            }
        } while (tmp < 3.01 && county < arr.size());  //whilestatement ensures that once all elements have been accounted for. 
                                                      //That a final trip that wasnt taken is counted.
        
        count++;
        b--;
        size=size - county;
    } 
    
    cout<<"\nNumber of Tries: " <<count<<endl;  //Prints out number of trips to the dumpster
    
    size = arr.size();
    
    //printf("Final Sorted: ");
    //for(int i = 0; i< size;i++) {
    //    printf("%.3f ", arr[i]); 
    //}

    printf("\n");
    system("pause");
	
    return 0;

}