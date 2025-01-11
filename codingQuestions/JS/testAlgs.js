import { binarySearch, dumbLinearSearch } from './algorithms.js';


function randomInt(min, max) {
  return Math.floor(Math.random() * (max - min) + min);
}


let val = 12

//random array
let array = []
let arrMax = randomInt(80,90)
for (let i = 0; i < arrMax; i++) {
  array.push(randomInt(0, 300));
}

console.log("arrmax: ", arrMax, "searchVal: ", val)
let dlRes = dumbLinearSearch(val, array)
console.log(`dumbSearch ${val} in ${array}:`, dlRes)

array = array.sort((a,b) => a-b)
let bsRes = binarySearch(val, array)
console.log(`binSearch ${val} in ${array}:`, bsRes)
