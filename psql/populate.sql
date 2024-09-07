-- mass populate tables from my initdb.sql shit.
-- how do this? good question.

-- members and facilities first, b/c bookings depend on them.
--first insert one into members so that the following populate works.
insert into ts.members
    (memid,firstname, surname, address, zipcode, telephone, recommendedby, joindate)
VALUES (1,'Kevin','Dillon','randomplace', 12345, '+1(234)567-8901', null, now());

--memid is an integer.... here's a random array selection of names.
INSERT INTO ts.members
    (memid,
        firstname, 
        surname, 
        address, zipcode, telephone, recommendedby, joindate)
VALUES (generate_series((select max(memid) from ts.members)::int+1, (select max(memid) from ts.members)::int+99),
        (ARRAY['Adam', 'Bill', 'Charlie', 'David', 'Ethan', 'Fred',
            'George', 'Hank', 'Ivan', 'Joseph', 'Kevin', 'Leo', 'Melvin', 'Ned',
            'Oscar', 'Peter', 'Quinn', 'Richard', 'Steven', 'Theodore', 'Ulrich',
            'Victor', 'Wendel', 'Xavier', 'Yanis', 'Zachary'])[floor(random()*26)+1],
        (ARRAY['Smith', 'Doe', 'Stevenson', 'Ralph', 'Palmer', 'Dillon',
            'George', 'Darvin', 'Culver', 'Oglevey', 'Carpenter', 'Stanley', 'Yelnats', 'Johnson',
            'Oscar', 'Jackson', 'Buttz', 'O''Leary', 'Steven', 'Theodore', 'Ulrich',
            'Victor', 'Wendel', 'Xavier', 'Yanis', 'Zachary'])[floor(random()*26)+1],
        'randomplace', 12345, '+1(234)567-8901', null, now());


--facilities with random costs and names. I want to ensure the "name" is unique.
INSERT INTO ts.facilities
    (facid,
        name,
        membercost, guestcost,
        initialoutlay, monthlymaintenance)
VALUES (generate_series((select coalesce(max(facid), 0) from ts.facilities)::int+1, (select coalesce(max(facid), 0) from ts.facilities)::int+50),
        (ARRAY['Tennis Court', 'Swimming Pool', 'Bowling Alley',
                'Basketball Court', 'Golf Course', 'Disc Golf Course',
                'Weight Training Gym', 'Running Track'])[floor(random()*8)+1] || ' ' ||
        (ARRAY[1,2,3,4,5,6,7,8,9,10])[floor(random()*10)+1],
        ROUND((random() * 1000)::numeric, 2), round((random() * 1000)::numeric, 2),
        round((random() * 1000)::numeric, 2), round((random() * 1000)::numeric, 2));

--bookings based on the facilities and members, do 200 at a time
--first select random id from facid, memid, start time is random month and year within 10 of now,
-- very icky and slow method, do order by random limit 1 multiple times..
INSERT INTO ts.bookings
    (facid, memid, starttime, slots)
select (select facid from ts.facilities where gen=gen offset floor(random()*(select count(facid) from ts.facilities)::int) limit 1),
        (select memid from ts.members where gen=gen offset floor(random()*(select count(memid) from ts.members)::int) limit 1),
        (date_add(now(), (((random()*2) - 1) * 1000 * '1 day'::INTERVAL))), (floor(random() * 10))
from generate_series(1,200) gen;
