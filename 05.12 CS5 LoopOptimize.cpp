void lower1(char *s) {
    for (size_t i = 0; i < strlen(s); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] -= ('A' - 'a');
}

void lower2(char *s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] -= ('A' - 'a');
}

size_t strlen(const char *s) {
	long length = 0;
	while(*s != '\0') {
		s++;
		length++;
	}
	return length;
}

//lower 1은 매 조건마다 strlen을 호출해야함

 
