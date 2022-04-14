import java.util.*;
import java.io.*;
import java.util.Arrays;

class Main {
  public static void main(String[] args) throws IOException{
    Scanner sc = new Scanner(System.in);
    int[] input = new int[7];
    for (int i = 0; i < 7; i++) {
      input[i] = sc.nextInt();
    }

    Arrays.sort(input);

    int[] newArr = new int[3];
    for(int i = 0; i < input.length; i++) {
      for(int j = i+1; j < input.length; j++) {
        for(int k = j+1; k < input.length;k++) {
          if(input[i] + input[j] + input[k] == input[input.length-1]) {
            newArr[0] = input[i];
            newArr[1] = input[j];
            newArr[2] = input[k];
          }
        }
      }
    }

    Arrays.sort(newArr);
    
    for (int i = 0; i < 2; i++) {
      System.out.print(newArr[i] + " ");
    }
    System.out.print(newArr[2]);
  }

}
