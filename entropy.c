/* Implementation Hints
Name Ashley Adams
Date 
Course
*/
#include <stdio.h>
#include <string.h>
#include <math.h>


double compute_entropy(const char *str) {
  if (str == NULL || str[0] == '\0') {
    return 0.0;
  }


  int freq[128] = {0};
  size_t len = strlen(str);

  for (size_t i =0; i< len; i++) {
    freq[(unsigned char)str[i]]++;
  }

  double entropy = 0.0;
  for (int i = 0; i <128; i++) {
    if (freq[i]>0) {
      double p = (double)freq[i] /len;
      entropy -= p * log2(p);
    } 
  }
return entropy;

}

int main(){
   // Prompt the user for a string
  char str[101];
  printf("Enter a string (up to 100 characters): ");
  fgets(str, sizeof(str), stdin);

  // Remove newline character from the input string, if present
  size_t len = strlen(str);
  if (len > 0 && str[len-1] == '\n') {
    str[len-1] = '\0';
  }

   // Compute the entropy of the string
   double entropy = compute_entropy(str); 
  
   // Display the computed entropy
   printf("\nEntropy: %.3f bits\n", entropy);

   // Display the character frequencies
     printf("\nCharacter Frequencies:\n");
     int freq[128] = {0};
     len = strlen(str);

     for (size_t i = 0; i < len; i++) {
      freq[(unsigned char)str[i]]++;
     }

     for (int i =0; i<128; i++){
      if (freq[i] > 0) {
        printf("%c: %d\n", i, freq[i]);
      }
     }
}


