function titleCase(str) {

  //regex replace the first character with the upper of itself and the rest with lower of itself...
  
  //easier is split by space, operate on the word, then rejoin with spaces between each item.

  const arr = str.split(" ").map((word) => word[0].toUpperCase() + word.slice(1).toLowerCase() );
  return arr.join(' ');

}

console.log(titleCase("I'm a little tea pot"));
