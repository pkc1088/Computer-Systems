int main(int argc, char**argv) {
    
    struct in_addr inaddr;
    unit16_t addr;
    char buf[MAXBUF];
    
    if(argc != 2) {
        fprintf(stderr, "usage : %s <hex number>\n", argc[0]);
        exit(0);
    }
    sscanf(argv[1], "%x", &addr); //sscanf�� atoi����� ��������
    inaddr.s_addr = htons(addr);

    if(!inet_ntop(AF_INET, &inaddr, buf, MAXBUF))
        unix_error("inet_ntop");
    printf("%s\n", buf);

    exit(0);
}
