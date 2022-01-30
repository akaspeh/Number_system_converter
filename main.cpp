#include <iostream>
#include <cmath>
using namespace std;

string from10(int num, int system2){
    int iteration=0;
    for(int i=num;i!=0;iteration++){
        i/=system2;
    }
    char a[iteration];
    int reminder;
    for(int i=0;num!=0;i++){
        reminder = num % system2;
        num/=system2;
        if(reminder<10){
            reminder=48+reminder;
        }
        else{
            reminder=55+reminder;
        }
        a[iteration-i-1] = reminder;
    }
    string s = "";
    for (int i = 0; i < iteration; i++) {
        s = s + a[i];
    }
    return s;
}




int to10(string num16,int system1) {
    int count=0;
    for(int i=0;num16[i] != '\0';i++,count++);
    int sumNum = 0;
    int *arr = new int[count];
    for (int i = 0; i < count; i++) {
        arr[i] = num16[i];
    }
    for (int i = 0; i < count; i++) {
        if(arr[i]>=48 && arr[i]<=48+(system1-1) || arr[i]>=65 && arr[i]<=65+((system1-1)-10));
        else{
            cout<<"out of bounds\n";
            return 0;
        }
    }
    for (int i = 0; i < count; i++) {
        if (arr[i] >= 65) // if it has more than 10 digits
        {
            sumNum += (arr[i] - 65 + 10) * pow(system1, count - i - 1);;
        } else {
            sumNum += (arr[i]-48)* pow(system1, count - i - 1);;
        }
    }
    delete [] arr;
    return sumNum;
}
int main() {
    int num;
    int testnum;
    int system1;
    int system2;
    string num16;
    cout << "I can work with numbers systems from 2 to 36\n";
    cout << "Entre number system for num which i convert in another: ";
    if (!(cin >> system1)){
        cout<<"out of bounds\n";
        return 0;
    }
    cout << "\n";
    cout << "Entre Natural number: ";
    cin >> num16;
    cout << "\n";
    cout << "Entre new number system: ";
    if (!(cin >> system2)){
        cout<<"out of bounds\n";
        return 0;
    }
    cout << "\n";
    if(!(system1 < 37 && system2 < 37 && system1 > 1 && system2 > 1)){
        cout<<"out of bounds\n";
        return 0;
    }
    num = to10(num16,system1);
    string s = from10(num,system2);
    cout << s << '\n';
    //Test
    testnum = to10(s,system2);
    string testnum16 = from10(testnum,system1);
    cout << "Test " << testnum16 <<endl;
    if (num16 == testnum16){
        cout << "All works";
    }
    return 0;
}