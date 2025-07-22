int dayOfYear(char* date) {
    int year, month, day;
    sscanf(date, "%d-%d-%d", &year, &month, &day);

    int days_in_month[] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        days_in_month[1] = 29;  
    }

    int day_of_year = 0;
    for (int i = 0; i < month - 1; i++) {
        day_of_year += days_in_month[i];
    }
    day_of_year += day;

    return day_of_year;
}