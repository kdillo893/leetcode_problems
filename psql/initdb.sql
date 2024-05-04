-- tables for testing purposes, utilizing exercises from
--    pgexercises.com as reference...

--placing this in a db entity separate from other stuff

--drop database if exists testdb;
CREATE DATABASE testdb IF NOT EXISTS;

--DROP SCHEMA IF EXISTS ts;

CREATE SCHEMA IF NOT EXISTS ts;

CREATE TABLE IF NOT EXISTS ts.members (
  memid         integer,
  firstname     varchar(200),
  surname       varchar(200),
  address       varchar(300),
  zipcode       integer,
  telephone     varchar(20),
  recommendedby integer,
  joindate      timestamp
);

CREATE TABLE IF NOT EXISTS ts.facilities(
  facid               integer,
  name                varchar(100),
  membercost          numeric,
  guestcost           numeric,
  initialoutlay      numeric,
  monthlymaintenance  numeric
);

CREATE TABLE IF NOT EXISTS ts.bookings (
  facid         integer,
  memid         integer,
  starttime     timestamp,
  slots         integer
);
