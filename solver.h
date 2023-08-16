enum roots_num {
    TWO, 
    SINGLE, 
    INFINITE, 
    NO, 
    ERR, // ошибка
};

roots_num solver(double roots[], double a, double b, double c);
