/***
 * Sir Lukas Robin
 * 2019-03-01
 * Statistic library  
 ***/


#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


//Organise data
vector<double> organise_data(vector<double> n)
{
    vector<double> sorted_data;
    double temp;
    for (int i = 0; i < n.size(); i++)
    {
        for (int j = 0; j < n.size(); j++)
        {
            if (n[i] < n[j])
            {
                temp = n[i];
                n[i] = n[j];
                n[j] = temp;
            }
        }
    }
    sorted_data = n;
    return sorted_data;
}


//mean//
double avg(vector<double> data1)
{
    vector<double> n = organise_data(data1);
    double sum = 0;
    for (int i = 0; i < n.size(); i++)
    {
        sum += n[i];
    }
    return sum /(n.size());
}
//media//
double median(vector<double> data1){
    vector<double> n=organise_data(data1);
    if (n.size()%2 == 0){
        //if the number of elements is even, the median is the average of the two innermost elements
        //For all n1 and n2 in the set of whole numbers, there exists an index of set S, i in the real numbers, such that n1<i<n2.
        int n_1 = floor(0.5*(n.size()-1));
        int n_2 = ceil(0.5*(n.size()-1));
        return (n[n_1]+n[n_2])/2;
    }
    else{
        int i= 0.5*(n.size()-1);
        return n[i];
    }
}
//mode//
double mode(vector<double> data1){
    vector<double> n=organise_data(data1);
    int count = 1;
    int max_count = 1;
    double mode = n[0];
    for (int i = 0; i < n.size()-1; i++){
        if (n[i] == n[i+1]){
            count++;
        }
        else{
            if (count > max_count){
                max_count = count;
                mode = n[i];
            }
            count = 1;
        }
    }
    return mode;
}
//Standard Deviation//
double standard_deviation(vector<double> data1){
    vector<double> n=organise_data(data1);
    double sum = 0;
    double mean = avg(n);
    sum = 0;
    for (int i = 0; i < n.size(); i++){
        sum += pow(n[i]-mean,2);
    }
    return sqrt(sum/(n.size()-1));
}
//This calculates the first quartile of the data//
double q1(vector<double> n){
    n = organise_data(n);
    vector<double> q1_range= vector<double>(n[0],median(n));
    return median(q1_range);
}
//This calculates the third quartile of the data//
double q3(vector<double> n){
    n = organise_data(n);
    vector<double> q3_range= vector<double>(median(n),n[n.size()-1]);
    return median(q3_range);
}

//This function returns the lower limit of the outliers//
double lower_limit_outliers(vector<double> data1){
    vector<double> n=organise_data(data1);
    
    double q1_value = q1(n);
    double q3_value = q3(n);
    double iqr = q3-q1;
    return q1-1.5*iqr;
}
//This function returns the upper limit of the outliers//
double upper_limit_outliers(vector<double> data1){
    vector<double> n=organise_data(data1);

    double q1 = q1(n);
    double q3 = q3(n);
    double iqr = q3-q1;
    return q3+1.5*iqr;
}
//This calculates variance//
double variance(vector<double> data1){
    vector<double> n=organise_data(data1);
    double sum = 0;
    double mean = avg(n);
    sum = 0;
    for (int i = 0; i < n.size(); i++){
        sum += pow(n[i]-mean,2);
    }
    return sum/(n.size()-1);
}
