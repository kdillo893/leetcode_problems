// Setup
const recordCollection = {
  2548: {
    albumTitle: 'Slippery When Wet',
    artist: 'Bon Jovi',
    tracks: ['Let It Rock', 'You Give Love a Bad Name']
  },
  2468: {
    albumTitle: '1999',
    artist: 'Prince',
    tracks: ['1999', 'Little Red Corvette']
  },
  1245: {
    artist: 'Robert Palmer',
    tracks: []
  },
  5439: {
    albumTitle: 'ABBA Gold'
  }
};

// Only change code below this line
function updateRecords(records, id, prop, value) {
  if (typeof records !== 'object' || !records.hasOwnProperty(id))
    return records;

  // we have a record with the ID, perform the operation...

  if (value === '') {
    delete records[id][prop];
  } else {
    //adding or editing a prop.
    if (prop === 'tracks') {
      //need to push onto list or if tracks doesn't exist, add then push
      if (!records[id].hasOwnProperty(prop)) {
        records[id][prop] = [];
      }
      
      //non-duplicate add, need this if condition.
      if (!records[id][prop].includes(value))
        records[id][prop].push(value);
    } else {
      records[id][prop] = value;
    }
  }




  return records;
}

updateRecords(recordCollection, 5439, 'artist', 'ABBA');

console.log(recordCollection);
