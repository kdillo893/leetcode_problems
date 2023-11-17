function truncateString(str, num) {
  //if the string is smaller than what we truncate, just return it.
  if (str.length <= num) {
    return str;
  }

  //slice from 0 to num, append with ...
  return str.slice(0,num) + "...";
}

let trunc = truncateString("A-tisket a-tasket A green and yellow basket", 8);
console.log(trunc);
