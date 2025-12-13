#include<iostream>
using namespace std;
int main(){
    float penCost, pencilCost, eraserCost;
      cout << "Enter the cost of a pen: ";
      cin>>penCost;

      cout << "Enter the cost of a pencil: ";
      cin>>pencilCost;

      cout << "Enter the cost of a eraser: ";
      cin>>eraserCost;

    float totCost = penCost + pencilCost + eraserCost;

    cout<< "total cost = "<< totCost << endl;
    cout<< "total cost with GST = "<< (totCost + (0.18 * totCost))<< endl;
    return 0;

}