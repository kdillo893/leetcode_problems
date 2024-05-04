-- mass populate tables from my initdb.sql shit.
-- how do this? good question.

-- members and facilities first, b/c bookings depend on them.
--memid is an integer....

INSERT INTO ts.members
    (memid, firstname, surname, address, zipcode, telephone, recommendedby, joindate)
VALUES (generate_series((select max(memid) from ts.members)::int+1, (select max(memid) from ts.members)::int+100),
        (ARRAY['Adam', 'Bill', 'Charlie', 'David', 'Ethan', 'Fred',
            'George', 'Hank', 'Ivan', 'Joseph', 'Kevin', 'Leo', 'Melvin', 'Ned',
            'Oscar', 'Peter', 'Quinn', 'Richard', 'Steven', 'Theodore', 'Ulrich',
            'Victor', 'Wendel', 'Xavier', 'Yanis', 'Zachary'])[floor(random()*26)+1],
        (ARRAY['Smith', 'Doe', 'Stevenson', 'Ralph', 'Palmer', 'Dillon',
            'George', 'Darvin', 'Culver', 'Oglevey', 'Carpenter', 'Stanley', 'Yelnats', 'Johnson',
            'Oscar', 'Jackson', 'Buttz', 'O''Leary', 'Steven', 'Theodore', 'Ulrich',
            'Victor', 'Wendel', 'Xavier', 'Yanis', 'Zachary'])[floor(random()*26)+1],
        'randomplace', 12345, '+1(234)567-8901', null, now());
