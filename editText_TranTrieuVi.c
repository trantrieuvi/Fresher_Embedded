
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Struct word lưu con trỏ đầu tiên của từ và độ dài từ
typedef struct word 
{
    char *firstChar;
    uint8_t w_length;
}word;

// Struct list_word lưu các từ và số từ có trong list
typedef struct list_word
{
    word word;
    uint8_t l_length;
}list_word;

//----------------Function----------------

uint8_t length_text(char *text);            // Hàm lấy độ dài của đoạn văn
uint8_t word_of_text(char *text);           // Hàm tính có bao nhiêu từ trong đoạn văn
list_word *word_separation(char *text);     // Hàm tách từng từ trong đoạn văn bỏ vào list_word               
void reverse_text(char *text);              // Hàm đảo đoạn văn
void upper_firstSentence(char *text);       // Hàm In hoa chữ cái đầu câu
void upper_text(char *text);                // Hàm in hoa cả đoạn văn
void lower_text(char *text);                // Hàm in thường cả đoạn văn
void show_text(char *text);                 // Hàm hiển thị đoạn văn

// Hàm lấy độ dài của đoạn văn
uint8_t length_text(char *text)
{
    uint8_t i = 0;
    while (text[i] != '\0') // '\0' là kí tự kết thúc chuỗi
    {
        i++;
    }
    return i+1;
}

// Hàm tính có bao nhiêu từ trong đoạn văn
uint8_t word_of_text(char *text)
{
    uint8_t count;
    uint8_t i = 0;
    for(int i = 0; i < length_text(text); i++)
    {
        if(text[i] == ' ') // Đếm từ thông qua dấu cách
        {
            count++;
        }
        i++;
    }
    return count+1;       // Sau từ cuối không có dấu cách nên phải cộng thêm 1
}

// Hàm tách từng từ trong đoạn văn bỏ vào list_word  
list_word *word_separation(char *text)
{
    uint8_t i = 0;
    uint8_t j = 0;
    uint8_t count = 0;
    list_word *n_list_word = (list_word*)(malloc(sizeof(list_word)*word_of_text(text))); // Cấp phát một cái list_word để lưu các từ trong đoạn văn
    n_list_word[i].word.firstChar = &text[i]; // Gán từ đầu tiên vô trước
    while (text[i] != '\0')
    {
        count++; // Đếm đến dấu cách có bao nhiêu kí tự để lưu kích thước của từng từ
        if(text[i] == ' ') // Sau đó những kí tự kế tiếp dấu cách là vị trí đầu tiên của từng từ
        {
            n_list_word[j].word.w_length = count-1; // Lưu kích thước của từ. -1 do bỏ dấu cách
            n_list_word[j+1].word.firstChar = &text[i+1]; // Lưu địa chỉ của kí tự bắt đầu của mỗi từ
            j++;
            count = 0;
        }
        if(text[i+1] == '\0') // Do sau từ cuối cùng không có dấu cách nên phải kiểm tra và lưu độ dài của từ cuối cùng
        {
            n_list_word[j].word.w_length = count; 
        }      
        i++;    
    }
    n_list_word->l_length = j+1; // Lưu lại số lượng từ vừa tách được 
    return n_list_word;
}

// Hàm đảo đoạn văn
void reverse_text(char *text)
{
    uint8_t k = 0;
    list_word * r_list_word = word_separation(text);
    char *new_text = (char*)malloc(sizeof(char)*length_text(text)); // Tao ra một đoạn văn bản mới để thao tác
    for(int8_t i = r_list_word->l_length - 1; i >=0; i--) // Tiền hàng đẩy từ trong list_word vào text mới theo chiều đảo lại và thêm vào dấu cách
    {
        for(uint8_t j = 0; j < r_list_word[i].word.w_length; j++)
        {
            new_text[k] = r_list_word[i].word.firstChar[j];
            k++;
        }
        new_text[k] = 32;  // Sau mỗi từ đẩy thêm dấu cách vào
        k++;
    }
    new_text[k] = '\0'; // Đẩy kí tự '\0' vào để kết thúc chuỗi
    for(k = 0; k < length_text(text); k++) // Copy đoạn văn mới vào đoạn văn cũ
    {
        text[k] = new_text[k];
    }
}   

// Hàm In hoa chữ cái đầu câu
void upper_firstSentence(char *text)
{
    uint8_t i = 0;
    if((text[0] >= 'a') && (text[0] <= 'z'))             // Kiểm tra ki tu thuong và viết hoa từ đầu tiên
    {
        text[0] -= 32;
    }
    while (text[i] != '\0')                             
    {
        if(text[i] == '.' && text[i+1] == ' ')           // Kiểm tra ki tu thuong và viết hoa từ đầu tiên
        {
            if((text[i+2] >= 97) && (text[i+2] <= 122))
            {
                text[i+2] -= 32;
            }
        }
        i++;
    }
}

// Hàm in hoa cả đoạn văn
void upper_text(char *text)
{
    uint8_t i = 0;
    while (text[i] != '\0')
    {
            if((text[i] >= 97) && (text[i] <= 122))
            {
                text[i] -= 32;
            }
        i++;
    }
}

// Hàm in thường cả đoạn văn
void lower_text(char *text)
{
    uint8_t i = 0;
    while (text[i] != '\0')
    {
            if((text[i] >= 'A') && (text[i] <= 'Z'))
            {
                text[i] += 32;
            }
        i++;
    }
}

// Hàm hiển thị đoạn văn
void show_text(char *text)
{
    uint8_t i = 0;
    while (text[i] != '\0')
    {
        printf("%c",text[i]);
        i++;
    }
    printf("\n");
}

//===================================== MAIN ===================

int main(int argc, char const *argv[])
{ 
    char str[] = "A man, woman and child were killed, police said. An additional adult woman was shot and was undergoing treatment at a local hospital, officials said.";
    upper_firstSentence(str);
    show_text(str);

    reverse_text(str);
    show_text(str);

    upper_text(str);
    show_text(str);

    lower_text(str);
    show_text(str);
    
    return 0;
}
