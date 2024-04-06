package com.kdill;
/**
 * CodingBat
 */
public class CodingBat {
  public static String endUp(String str) {
    if (str.length() < 3) {
      return str.toUpperCase();
    }

    // pull the last 3, upper, and return concat
    String last3 = str.substring(str.length() - 3);
    return str.substring(0, str.length() - 3).concat(last3.toUpperCase());
  }

  public static String everyNth(String str, int n) {
    if (n <= 1) {
      return str;
    }

    StringBuilder stringBuilder = new StringBuilder();
    // option one is just for loop with length...
    for (int i = 0; i < str.length(); i += n) {
      stringBuilder.append(str.charAt(i));
    }

    return stringBuilder.toString();
  }

  public static boolean stringE(String str) {

    // counting characters in a string... hmmm
    // fun way would be loop while indexOf(e) is non negative..
    int lastIndex = str.indexOf('e', 0);
    int count = 0;
    // System.out.printf("string: %s, index=%d \n", str, lastIndex);

    while (lastIndex >= 0) {
      count++;
      lastIndex = str.indexOf('e', lastIndex +1);
      // System.out.printf("string: %s, index=%d \n", str, lastIndex);
    }

    return count <= 3 && count >= 1;
  }

}
