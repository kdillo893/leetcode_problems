--
-- PostgreSQL database dump
--

-- Dumped from database version 16.1
-- Dumped by pg_dump version 16.1

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: ts; Type: SCHEMA; Schema: -; Owner: kdill
--

CREATE SCHEMA ts;


ALTER SCHEMA ts OWNER TO kdill;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: bookings; Type: TABLE; Schema: ts; Owner: kdill
--

CREATE TABLE ts.bookings (
    facid integer,
    memid integer,
    starttime timestamp without time zone,
    slots integer
);


ALTER TABLE ts.bookings OWNER TO kdill;

--
-- Name: facilities; Type: TABLE; Schema: ts; Owner: kdill
--

CREATE TABLE ts.facilities (
    facid integer NOT NULL,
    name character varying(100),
    membercost numeric,
    guestcost numeric,
    initialoutlay numeric,
    monthlymaintenance numeric
);


ALTER TABLE ts.facilities OWNER TO kdill;

--
-- Name: members; Type: TABLE; Schema: ts; Owner: kdill
--

CREATE TABLE ts.members (
    memid integer NOT NULL,
    firstname character varying(200),
    surname character varying(200),
    address character varying(300),
    zipcode integer,
    telephone character varying(20),
    recommendedby integer,
    joindate timestamp without time zone
);


ALTER TABLE ts.members OWNER TO kdill;

--
-- Data for Name: bookings; Type: TABLE DATA; Schema: ts; Owner: kdill
--

COPY ts.bookings (facid, memid, starttime, slots) FROM stdin;
\.


--
-- Data for Name: facilities; Type: TABLE DATA; Schema: ts; Owner: kdill
--

COPY ts.facilities (facid, name, membercost, guestcost, initialoutlay, monthlymaintenance) FROM stdin;
\.


--
-- Data for Name: members; Type: TABLE DATA; Schema: ts; Owner: kdill
--

COPY ts.members (memid, firstname, surname, address, zipcode, telephone, recommendedby, joindate) FROM stdin;
0	GUEST	GUEST	\N	\N	\N	\N	2024-05-04 17:26:10.587393
\.


--
-- Name: facilities facilities_pkey; Type: CONSTRAINT; Schema: ts; Owner: kdill
--

ALTER TABLE ONLY ts.facilities
    ADD CONSTRAINT facilities_pkey PRIMARY KEY (facid);


--
-- Name: members members_pkey; Type: CONSTRAINT; Schema: ts; Owner: kdill
--

ALTER TABLE ONLY ts.members
    ADD CONSTRAINT members_pkey PRIMARY KEY (memid);


--
-- Name: bookings bksfacfk; Type: FK CONSTRAINT; Schema: ts; Owner: kdill
--

ALTER TABLE ONLY ts.bookings
    ADD CONSTRAINT bksfacfk FOREIGN KEY (facid) REFERENCES ts.facilities(facid);


--
-- Name: bookings bksmemfk; Type: FK CONSTRAINT; Schema: ts; Owner: kdill
--

ALTER TABLE ONLY ts.bookings
    ADD CONSTRAINT bksmemfk FOREIGN KEY (memid) REFERENCES ts.members(memid);


--
-- Name: members memrecfk; Type: FK CONSTRAINT; Schema: ts; Owner: kdill
--

ALTER TABLE ONLY ts.members
    ADD CONSTRAINT memrecfk FOREIGN KEY (recommendedby) REFERENCES ts.members(memid);


--
-- PostgreSQL database dump complete
--

