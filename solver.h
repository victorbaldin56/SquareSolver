enum roots_num {
    NO,
    SINGLE,
    TWO,
    INFINITE,
    ERR = -1, 
};

roots_num solve(double roots[], double a, double b, double c);
