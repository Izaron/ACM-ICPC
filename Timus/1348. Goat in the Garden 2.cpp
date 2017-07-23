#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    double px = 0, py = 0;
    double length;

    double A = 0;
    double B = -1;
    double C = 0;
    double slope = 0;

    cin>>x1>>y1>>x2>>y2>>px>>py>>length;

    // get the equation of pineapple line in the form Ax + By + c = 0

    if((x2 - x1) != 0){
        slope = (y2 - y1) / (x2 - x1);
        A = slope;
        C = y2 - slope * x2;
    }

    if((x2 - x1) == 0){
        A = 1;
        B = 0;
        C = -x1;
    }

    // now since we have Ax + By + C = 0
    // we can find the shortest distance between the point and the line

    double short_dist = fabs(A*px + B*py + C) / sqrt(pow(A, 2) + pow(B, 2));
    double dist_x1y1 = fabs(sqrt(pow(px-x1, 2) + pow(py-y1, 2)));
    double dist_x2y2 = fabs(sqrt(pow(px-x2, 2) + pow(py-y2, 2)));

    // once we have calculated the shorted distance, we need to
    // find out the point lying on that pineapple line which is
    // closest to the peg

    double slope_new = 0;
    double B_new = 0;
    double C_new = 0;
    double A_new = 0;
    bool status = true;

    if((x2 - x1) == 0){
        slope_new = 0; // the other line has slope of inifinity, so this is parallel
        B_new = 1;
        A_new = 0;
        C_new = -py;
        status = false;
    }

    if((y2 - y1) == 0){
        B_new = 0;
        A_new = 1;
        C_new = -px;
        status = false;
    }

    if(status){
        slope_new = -1.0/slope;
        C_new = py - slope_new*px;
        A_new = slope_new;
        B_new = -1;
    }

    // calculating the point of intersection

    double inter_X = (-C*B_new - B*(-C_new)) / (A*B_new - B*A_new);
    double inter_Y = (A*(-C_new) - (-C*A_new))/(A*B_new - B*A_new);

    // now check whether this point lies between the given points or not ?
    // to do that we need to check whether both of the above calculated
    // coordinates lie between the range of x1, y1 and x2, y2

    double min_x_coor = min(x1, x2);
    double min_y_coor = min(y1, y2);
    double max_x_coor = max(x1, x2);
    double max_y_coor = max(y1, y2);

    if(inter_X >= min_x_coor && inter_X <= max_x_coor && inter_Y >= min_y_coor && inter_Y <= max_y_coor){
        // this means, the point lies on the line
        double one_pineapple_distance = short_dist - length;
        if(one_pineapple_distance <= 0){
            cout<<"0.00"<<endl;
        }
        else
            printf("%.2f\n", one_pineapple_distance);

        // now to eat all the pineapples
        double larger_distance = max(dist_x1y1, dist_x2y2);
        if(larger_distance - length <= 0){
            cout<<"0.00"<<endl;
        }
        else
            printf("%.2f\n", larger_distance - length);
    }

    // or else the perpendicuar point does not lies on the line
    else{
        // first shorter one
        double shorter_distance = min(dist_x1y1, dist_x2y2);
        double larger_distance = max(dist_x1y1, dist_x2y2);

        double pineapple_1 = shorter_distance - length;
        if(pineapple_1 <= 0){
            cout<<"0.00"<<endl;
        }
        else
            printf("%.2f\n", pineapple_1);

        double pineapple_all = larger_distance - length;
        if(pineapple_all <= 0){
            cout<<"0.00"<<endl;
        }
        else
            printf("%.2f\n", pineapple_all);
    }
    return 0;
}