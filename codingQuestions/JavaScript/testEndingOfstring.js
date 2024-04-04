function confirmEnding(str, target) {

  //two ways:
  ///regex test against end of string with /${target}$/ ... this would take some knowledge of syntax.
  ///slice from the end of str for the length of target... test if it matches the expected target


  // let substr = str.slice(str.length - target.length);
  // return str.slice(str.length - target.length) === target;
  const regexTarget = new RegExp(target+"$");
  return regexTarget.test(str);
}

confirmEnding("Bastian", "n");
