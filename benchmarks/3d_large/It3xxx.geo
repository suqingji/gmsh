lc = 1.65;
cli = lc;
cle1 = lc;
cle2 = lc;
cle3 = lc;
cl3 = 1.0e10;
cl4 = 1.0e10;
res = 3.535533905932737e+002;
ris = 1.767766952966369e+002;
res1 = 1.294095225512604e+002;
rec1 = 4.829629131445342e+002;
re = 500;
ri = 350;
h = 25;
g0 = 10;
l = -re;
r = 2200;
up = -re-g0;
dw = up-600;
h2 = 400;
h3 = 600;
Point(1) = {0, -ri, 0, cli};
Point(2) = {ri, 0, 0, cli};
Point(3) = {0, ri, 0, cli};
Point(4) = {-ri, 0, 0, cli};
Point(5) = {-res, -res, 0, cle2};
Point(6) = {-res1, -rec1, 0, cle3};
Point(7) = {0, -re, 0, cle1};
Point(8) = {res1, -rec1, 0, cle3};
Point(9) = {res, -res, 0, cle2};
Point(10) = {re, 0, 0, cle2};
Point(11) = {res, res, 0, cle2};
Point(12) = {0, re, 0, cle2};
Point(13) = {-res, res, 0, cle2};
Point(14) = {-re, 0, 0, cle2};
Point(15) = {0, -ri, h, cli};
Point(16) = {ri, 0, h, cli};
Point(17) = {0, ri, h, cli};
Point(18) = {-ri, 0, h, cli};
Point(19) = {-res, -res, h, cle2};
Point(20) = {-res1, -rec1, h, cle3};
Point(21) = {0, -re, h, cle1};
Point(22) = {res1, -rec1, h, cle3};
Point(23) = {res, -res, h, cle2};
Point(24) = {re, 0, h, cle2};
Point(25) = {res, res, h, cle2};
Point(26) = {0, re, h, cle2};
Point(27) = {-res, res, h, cle2};
Point(28) = {-re, 0, h, cle2};
Point(29) = {l, up, -h2, cl3};
Point(30) = {l, dw, -h2, cl3};
Point(31) = {r, dw, -h2, cl3};
Point(32) = {r, up, -h2, cl3};
Point(33) = {l, up, h3, cl3};
Point(34) = {l, dw, h3, cl3};
Point(35) = {r, dw, h3, cl3};
Point(36) = {r, up, h3, cl3};
Point(37) = {0, 0, h, cli};
Point(38) = {0, 0, 0, cli};
Circle(1) = {19, 37, 20};
Circle(2) = {20, 37, 21};
Circle(3) = {21, 37, 22};
Circle(4) = {22, 37, 23};
Circle(5) = {23, 37, 24};
Circle(6) = {24, 37, 25};
Circle(7) = {25, 37, 26};
Circle(8) = {26, 37, 27};
Circle(9) = {27, 37, 28};
Circle(10) = {28, 37, 19};
Circle(11) = {5, 38, 6};
Circle(12) = {6, 38, 7};
Circle(13) = {7, 38, 8};
Circle(14) = {8, 38, 9};
Circle(15) = {9, 38, 10};
Circle(16) = {10, 38, 11};
Circle(17) = {11, 38, 12};
Circle(18) = {12, 38, 13};
Circle(19) = {13, 38, 14};
Circle(20) = {14, 38, 5};
Circle(21) = {15, 37, 16};
Circle(22) = {16, 37, 17};
Circle(23) = {17, 37, 18};
Circle(24) = {18, 37, 15};
Circle(25) = {1, 38, 2};
Circle(26) = {2, 38, 3};
Circle(27) = {3, 38, 4};
Circle(28) = {4, 38, 1};
Line(29) = {5, 19};
Line(30) = {6, 20};
Line(31) = {7, 21};
Line(32) = {8, 22};
Line(33) = {9, 23};
Line(34) = {10, 24};
Line(35) = {11, 25};
Line(36) = {12, 26};
Line(37) = {13, 27};
Line(38) = {14, 28};
Line(39) = {4, 18};
Line(40) = {1, 15};
Line(41) = {2, 16};
Line(42) = {3, 17};
Line(43) = {30, 34};
Line(44) = {34, 33};
Line(45) = {33, 29};
Line(46) = {29, 30};
Line(47) = {33, 36};
Line(48) = {36, 35};
Line(49) = {35, 34};
Line(50) = {35, 31};
Line(51) = {31, 32};
Line(52) = {32, 36};
Line(53) = {30, 31};
Line(54) = {29, 32};
Line Loop(55) = {29, 1, -30, -11};
Ruled Surface(56) = {-55};
Line Loop(57) = {30, 2, -31, -12};
Ruled Surface(58) = {-57};
Line Loop(59) = {31, 3, -32, -13};
Ruled Surface(60) = {-59};
Line Loop(61) = {32, 4, -33, -14};
Ruled Surface(62) = {-61};
Line Loop(63) = {33, 5, -34, -15};
Ruled Surface(64) = {-63};
Line Loop(65) = {34, 6, -35, -16};
Ruled Surface(66) = {-65};
Line Loop(67) = {35, 7, -36, -17};
Ruled Surface(68) = {-67};
Line Loop(69) = {36, 8, -37, -18};
Ruled Surface(70) = {-69};
Line Loop(71) = {19, 38, -9, -37};
Ruled Surface(72) = {71};
Line Loop(73) = {20, 29, -10, -38};
Ruled Surface(74) = {73};
Line Loop(75) = {40, -24, -39, 28};
Ruled Surface(76) = {-75};
Line Loop(77) = {40, 21, -41, -25};
Ruled Surface(78) = {77};
Line Loop(79) = {41, 22, -42, -26};
Ruled Surface(80) = {79};
Line Loop(81) = {23, -39, -27, 42};
Ruled Surface(82) = {81};
Line Loop(83) = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
Line Loop(84) = {23, 24, 21, 22};
Plane Surface(85) = {83, 84};
Line Loop(86) = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
Line Loop(87) = {27, 28, 25, 26};
Plane Surface(88) = {-86, -87};
Line Loop(89) = {54, 52, -47, 45};
Plane Surface(90) = {-89};
Line Loop(91) = {44, 45, 46, 43};
Plane Surface(92) = {91};
Line Loop(93) = {49, -43, 53, -50};
Plane Surface(94) = {93};
Line Loop(95) = {50, 51, 52, 48};
Plane Surface(96) = {95};
Line Loop(97) = {49, 44, 47, 48};
Plane Surface(98) = {-97};
Line Loop(99) = {54, -51, -53, -46};
Plane Surface(100) = {99};
Surface Loop(101) = {85, 56, 88, 74, 72, 70, 68, 66, 64, 62, 60, 58, 82, 76, 78, 80};
Volume(102) = {101};
Surface Loop(103) = {90, 92, 98, 96, 94, 100};
Volume(104) = {103};
Physical Surface(105) = {56, 58, 60, 62, 64, 66, 68, 70, 72, 74};
Physical Surface(106) = {90};
Physical Volume(107) = {102};
Physical Volume(108) = {104};
