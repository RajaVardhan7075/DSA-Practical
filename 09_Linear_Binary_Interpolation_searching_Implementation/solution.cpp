#include <bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int n, int target){
    for(int i=0; i<n; i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}
int binary_search(int arr[], int n, int target){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]<target){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}
int interpolation_search(int arr[], int n, int target){
    int low=0, high=n-1;
    while(low<=high && target>=arr[low] && target<=arr[high]){
        if(low==high){
            if(arr[low]==target){
                return low;
            }
            return -1;
        }
        int position = low+((double)(high-low)/(arr[high]-arr[low]))*(target-arr[low]);
        if(arr[position]==target){
            return position;
        }else if(arr[position]<target){
            low=position+1;
        }else{
            high=position-1;
        }
    }
    return -1;
}
void printResult(string name, int index, int target){
    if(index!=-1){
        cout<<name<<": "<<target<<" found at index"<<index<<"\n";
    }else{
        cout<<"Element is not found\n";
    }
}
int main() {
	int n;
	cout<<"Enter number of elements : \n";
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
	    cin>>arr[i];
	}
	sort(arr, arr+n);
	int target;
	cout<<"Enter the target value : \n";
	cin>>target;
	printResult("Linear Search ", linear_search(arr, n, target), target);
	printResult("Binary Search ", binary_search(arr, n, target), target);
	printResult("Interpolation Search ", interpolation_search(arr, n, target), target);
	return 0;
}
