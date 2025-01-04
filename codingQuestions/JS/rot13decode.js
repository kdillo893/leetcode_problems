function rot13(str) {

  const rotChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".split("");

  let resultString = "";

  for (let i = 0; i < str.length; i++) {
    const thisChar = str[i];

    //regex match non A-Z, skip
    if (/[^A-Z]/.test(thisChar)) {
      resultString += thisChar;
      continue;
    }

    //for each character of the string, index, add 13, mod length of rotChars.
    let charIdx = rotChars.indexOf(thisChar);
    resultString += rotChars[(charIdx + 13) % rotChars.length];
  }

  return resultString;
}

rot13("SERR PBQR PNZC");
