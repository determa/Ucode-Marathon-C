int mx_strcmp(const char *s1, const char *s2) {
    const unsigned char *v1 = (const unsigned char *) s1; 
    const unsigned char *v2 = (const unsigned char *) s2;

    while ((*v1 == *v2) && (*v1 != '\0' || *v2 != '\0' )) {
        v1++;
        v2++;
    }
    return (*v1 > *v2) - (*v1 < *v2);
} 

