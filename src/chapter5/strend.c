/*
 * exercise 5-4
 * return 1, if string t occurs at the end of the string s,
 * otherwise, return 0
 */
int strend(char *s, char *t) {
	/* quick check the case of empty string */
	if (*s == '\0' || *t == '\0') return 0;
	char *shead = s;
	char *thead = t;
	/* skip to the end of s */
	while (*s != '\0') s++;
	/* skip to the end of t */
	while (*t != '\0') t++;
	/* compare character by character from the end */
	while (t >= thead) {
		if (*t != *s || s < shead) return 0;
		t--; s--;
	}
	return 1;
}
