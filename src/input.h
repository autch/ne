#ifndef input_h
#define input_h

/* input.c */
void LeditInput(int c, int contrl_flag);
void Ledit(int contrl_flag);
void InputAndCrt(int key);
char *HisGets(char *dest, const char *message, int listID);
int GetS(const char *message, char *buffer);

#endif /* input_h */
