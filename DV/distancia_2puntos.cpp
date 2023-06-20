#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct Point {
  double x;
  double y;
};

double distance(const Point &p1, const Point &p2) {
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  return sqrt(dx * dx + dy * dy);
}

bool compareX(const Point &p1, const Point &p2) { return p1.x < p2.x; }

bool compareY(const Point &p1, const Point &p2) { return p1.y < p2.y; }

pair<Point, Point> closestPairStrip(const vector<Point> &strip, double minDist,
                                    pair<Point, Point> &minPair) {
  pair<Point, Point> minstripPair = minPair;
  double minDistance = minDist;

  int stripSize = strip.size();
  for (int i = 0; i < stripSize - 1; ++i) {
    for (int j = i + 1; j < stripSize; ++j) {
      double dist = distance(strip[i], strip[j]);
      if (dist < minDistance) {
        minDistance = dist;
        minstripPair.first = strip[i];
        minstripPair.second = strip[j];
      }
    }
  }

  return minstripPair;
}

pair<Point, Point> closestPairRec(vector<Point> &pointsSortedByX,
                                  vector<Point> &pointsSortedByY) {
  int n = pointsSortedByX.size();
  // Base case: if there are less than 2 points, no closest pair exists
  if (n < 2) {
    return make_pair(pointsSortedByX[0], Point{0.0, 0.0});
  }

  // Base case: if there are exactly 2 points, return them as the closest pair
  if (n == 2) {
    return make_pair(pointsSortedByX[0], pointsSortedByX[1]);
  }

  // Divide the points into two halves
  int mid = n / 2;
  vector<Point> leftPointsSortedByX(pointsSortedByX.begin(),
                                    pointsSortedByX.begin() + mid);
  vector<Point> rightPointsSortedByX(pointsSortedByX.begin() + mid,
                                     pointsSortedByX.end());

  // Find the median x-coordinate
  double medianX = pointsSortedByX[mid].x;

  // Split the points into two halves based on the median x-coordinate
  vector<Point> leftPointsSortedByY;
  vector<Point> rightPointsSortedByY;

  for (const Point &point : pointsSortedByY) {
    if (point.x < medianX) {
      leftPointsSortedByY.push_back(point);
    } else {
      rightPointsSortedByY.push_back(point);
    }
  }

  // Recursively find the closest pairs in the left and right halves
  pair<Point, Point> leftClosestPair =
      closestPairRec(leftPointsSortedByX, leftPointsSortedByY);
  pair<Point, Point> rightClosestPair =
      closestPairRec(rightPointsSortedByX, rightPointsSortedByY);

  // Determine the closer pair between the left and right halves
  double leftDist = distance(leftClosestPair.first, leftClosestPair.second);
  double rightDist = distance(rightClosestPair.first, rightClosestPair.second);
  double minDist = min(leftDist, rightDist);
  pair<Point, Point> minPair =
      (leftDist < rightDist) ? leftClosestPair : rightClosestPair;
  // Build the strip containing points within the minimum distance from the
  // median x-coordinate
  vector<Point> strip;

  for (const Point &point : pointsSortedByY) {
    if (abs(point.x - medianX) < minDist) {
      strip.push_back(point);
    }
  }
  //Encontrar el par mas cercano dentro de los puntos mas cercanos a la linea de division del medio "|".
  pair<Point, Point> stripClosestPair =
      closestPairStrip(strip, minDist, minPair);
  // Determinar el par mas cercano entre los puntos mas cercanos a la linea de division del medio "|" y el par mas cercano anteriormente obtenido.
  double stripDist = distance(stripClosestPair.first, stripClosestPair.second);
  if (stripDist < minDist) {
    minDist = stripDist;
    minPair = stripClosestPair;
  }
  return minPair;
}

pair<Point, Point> closestPair(const vector<Point> &points) {
  vector<Point> pointsSortedByX = points;
  vector<Point> pointsSortedByY = points;
  sort(pointsSortedByX.begin(), pointsSortedByX.end(), compareX);
  sort(pointsSortedByY.begin(), pointsSortedByY.end(), compareY);
  return closestPairRec(pointsSortedByX, pointsSortedByY);
}

int main() {
  int n = 4;

  vector<Point> points(n);

  /*points[0].x = -1;
  points[0].y = 3;
  points[1].x = 2;
  points[1].y = -3;
  points[2].x = 1.5;
  points[2].y = 1.5;
  points[3].x = 1;
  points[3].y = 1;
  points[4].x = 4.5;
  points[4].y = 2;
  points[5].x = 3;
  points[5].y = 2.5;
  points[6].x = 2.5;
  points[6].y = 3;
  points[7].x = 2;
  points[7].y = 5;
  points[8].x = 4;
  points[8].y = 2;*/

  points[0].x = 1;
  points[0].y = 3;
  points[1].x = 2;
  points[1].y = 4;
  points[2].x = 3;
  points[2].y = 5;
  points[3].x = 4;
  points[3].y = 6;

  pair<Point, Point> closest = closestPair(points);
  cout << "Pares más Cercanos: (" << closest.first.x << ", " << closest.first.y
       << ") y (" << closest.second.x << ", " << closest.second.y << ")"
       << endl;

  return 0;
}
