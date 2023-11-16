function largestOfFour(arr) {
  //for each sub-array, get the largest, new array with only the largest in sequence matching the arrays.
  const newArr = new Array(arr.length);

  for (let i = 0; i < arr.length; i++) {
    const subArr = arr[i];
    let largest = subArr[0];
    for (let j = 1; j < subArr.length; j++) {
      if (subArr[j] > largest)
        largest = subArr[j];
    }
    newArr[i] = largest;
  }

  return newArr;
}

largestOfFour([[4, 5, 1, 3], [13, 27, 18, 26], [32, 35, 37, 39], [1000, 1001, 857, 1]]);
