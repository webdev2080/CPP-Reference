#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Note: 1-letter variable names are typically avoided,
// but used below where standard in physics.

const double PI_CONST = 3.14159265;

// Given time, angle, velocity, and gravity
// Update x and y values
void ObjectTrajectory(double t, double a, double v, double g,
                double& x, double& y) {
   x = v * t * cos(a);
   y = v * t * sin(a) - 0.5 * g * t * t;
   return;
}

// Convert degree value to radians
double DegToRad(double inDeg) {
   return ((inDeg * PI_CONST) / 180.0);
}

int main() {
   const double GRAVITY  = 9.8; // Earth gravity (m/s^2)
   double launchAngle    = 0.0; // Angle of launch (rad)
   double launchVelocity = 0.0; // Velocity (m/s)
   double elapsedTime    = 1.0; // Time (s)
   
   double yLoc = -1.0;          // Obj's location above ground (m)
   double xLoc = 0.0;           // Obj's horiz. loc. from start (m)
   
   cout << "Launch angle (deg): ";
   cin >> launchAngle;
   launchAngle = DegToRad(launchAngle); // To radians
   
   cout << "Launch velocity (m/s): ";
   cin >> launchVelocity;
   
   cout << "Initial height (m): ";
   cin >> yLoc;
   
   while ( yLoc > 0.0 ) { // While above ground
      cout << "Time " << fixed << setprecision(0)
      << setw(3) << elapsedTime
      << "   x = " << setw(3) << xLoc
      << "   y = " << setw(3) << yLoc
      << endl;
      ObjectTrajectory(elapsedTime, launchAngle, launchVelocity,
                       GRAVITY, xLoc, yLoc);
      elapsedTime = elapsedTime + 1.0;
   }
   
   return 0;
}
