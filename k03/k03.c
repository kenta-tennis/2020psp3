#include <stdio.h>
#include <string.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    int start,pos;
    int text_len,key_len;

    text_len = strlen(text);
    key_len = strlen(key);
    
    for(start = 0; start < text_len - key_len; start++)
    {
        for(pos = 0; pos < key_len; pos++)
        {
            if(text[start + pos] != key[pos])
            {
                break;
            }

            if(pos == key_len - 1)
            {
                return text+start;
            }            
        }
    }
    
    return NULL;
}

char* BMSearch(char text[], char key[])
{
    int index,key_index;
    int text_len=0,key_len=0;
    int table[256];
    int a,b;

    for(a=0;text[a]!='\0';a++)
    {
        text_len++;
    }

    for(b=0;key[b]!='\0';b++)
    {
        key_len++;
    }

    for(a=0;a<=255;a++)
    {
        table[a] = key_len;
    }

    for(a=0;a<key_len;a++)
    {
        table[key[a]] = key_len-(a+1);
    }

    index = key_len-1;

    while(index<=text_len-1)
    {

        for(a=0;a<=key_len-1;a++)
        {

            if(text[index-a] == key[key_len-a-1])
            {
                if(a==key_len-1)
                {
                    return text+index-(key_len-1);
                }
                else
                {
                    
                }
                
            }
            else
            {
                break;
            }
            
        }

        key_index = index-a+table[text[index-a]];

        if(key_index>index)
        {
            index = key_index;
        }
        else
        {
            index++;
        }
        
    }

    return NULL;

}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}