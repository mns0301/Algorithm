int n, t, s;
main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &t);
        s += --t;
    }
    printf("%d", ++s);
}