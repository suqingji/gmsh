Point(1) = {-0.5, -0.5, 0.0, 0.025};
Point(2) = {0.5, -0.5, 0.0, 0.025};
Point(3) = {0.5, 0.5, 0.0, 0.025};
Point(4) = {-0.5, 0.5, 0.0, 0.025};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Periodic Curve {3} = {-1};
Periodic Curve {2} = {-4};
Line Loop(1) = {1, 2, 3, 4};
Plane Surface(1) = {1};
Physical Point(1) = {1};
Physical Point(2) = {1, 2, 3, 4};
Physical Point(3) = {2};
Physical Point(4) = {3};
Physical Point(5) = {4};
Physical Line(1) = {1};
Physical Line(2) = {1, 2, 3, 4};
Physical Line(3) = {2};
Physical Line(4) = {3};
Physical Line(5) = {4};
Physical Surface(1) = {1};