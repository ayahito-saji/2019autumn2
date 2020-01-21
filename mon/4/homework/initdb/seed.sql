create table users
(
  id serial primary key,
  username varchar(50) unique not null,
  password varchar(50) not null,
  email varchar(255) unique not null
);

insert into users (username, password, email) values ('keid', 'keidpass', 'keid@developer.com');
insert into users (username, password, email) values ('jobs', 'jobspass', 'jobs@developer.com');
insert into users (username, password, email) values ('mask', 'maskpass', 'mask@developer.com');
