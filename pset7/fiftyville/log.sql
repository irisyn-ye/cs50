-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description
FROM crime_scene_reports
WHERE year == 2020 AND month == 7 AND DAY = 28 AND street = "Chamberlin Street"

-- crime_scene_report:
-- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
-- Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

SELECT transcript
FROM interviews
WHERE year == 2020 AND month == 7 AND DAY = 28 and transcript LIKE "%courthouse%"

-- got three transcripts
-- transcript1
-- Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
-- If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
SELECT name
FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE year == 2020 AND month == 7 AND day == 28 AND hour == 10 AND minute >= 15 AND minute <= 25 AND activity = "exit"
-- 1st suspect list: Patrick, Ernest, Amber, Danielle, Roger, Elizabeth, Russell, Evelyn

-- transcript2
-- I don't know the thief's name, but it was someone I recognized.
-- Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
SELECT name
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE year == 2020 AND month == 7 AND day == 28 AND transaction_type == "withdraw" AND atm_location == "Fifer Street"
-- 2nd suspect list: Ernest, Russell, Roy, Bobby, Elizabeth, Danielle, Madison, Victoria

-- transcript3
-- As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
-- The thief then asked the person on the other end of the phone to purchase the flight tickets.
SELECT name
FROM people
JOIN passengers on people.passport_number = passengers.passport_number
WHERE flight_id = (
    SELECT id
    FROM flights
    WHERE year == 2020 AND month == 7 AND day == 29
    ORDER BY hour, minute ASC
    LIMIT 1
)
-- 3rd suspect list: Doris, Roger, Ernest, Edward, Evelyn, Madison, Bobby, Danielle

-- suspects for now: Ernest and Danielle

-- check phone calls
SELECT distinct name
FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE year == 2020 AND month == 7 AND day == 28 AND duration < 60
-- suspects from phone calls: Roger, Evelyn, Ernest, Madison, Russell, Kimberly, Bobby, Victoria

-- thief: Ernest

-- check destination
SELECT city
FROM airports
WHERE id = (
    SELECT destination_airport_id
    FROM flights
    WHERE year == 2020 AND month == 7 AND day == 29
    ORDER BY hour, minute ASC
    LIMIT 1
)
-- destination: London

-- check accomplice
SELECT name
FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE year == 2020 AND month == 7 AND day == 28 AND duration < 60 AND caller = (
    SELECT phone_number
    FROM people
    WHERE name = "Ernest"
)
-- accomplice: Berthold

