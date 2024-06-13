-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 21, 2024 at 09:20 AM
-- Server version: 10.4.28-MariaDB
-- PHP Version: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `companyeventregistration`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `admin_ID` int(11) NOT NULL,
  `Admin_Name` varchar(50) NOT NULL,
  `Admin_Age` int(3) NOT NULL,
  `Admin_gender` varchar(7) NOT NULL,
  `Admin_Tel` varchar(20) NOT NULL,
  `Admin_Password` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`admin_ID`, `Admin_Name`, `Admin_Age`, `Admin_gender`, `Admin_Tel`, `Admin_Password`) VALUES
(1, 'Low Xiao Qian', 21, 'female', '0166188184', 'LXQ');

-- --------------------------------------------------------

--
-- Table structure for table `events`
--

CREATE TABLE `events` (
  `Events_ID` int(11) NOT NULL,
  `Events_Name` varchar(50) DEFAULT NULL,
  `Events_Date` varchar(20) DEFAULT NULL,
  `Events_Time` varchar(20) DEFAULT NULL,
  `Events_Venue` varchar(100) DEFAULT NULL,
  `Events_capacity` int(11) DEFAULT NULL,
  `Tutor_ID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `events`
--

INSERT INTO `events` (`Events_ID`, `Events_Name`, `Events_Date`, `Events_Time`, `Events_Venue`, `Events_capacity`, `Tutor_ID`) VALUES
(301, 'Coding Class', '2024-01-23', '2:00p.m. - 3:00p.m.', 'Dewan Shah Bandar', 28, 100),
(302, 'Creative Development Workshop', '2024-01-29', '3:00p.m. - 5:00p.m.', 'Dewan seminar', 27, 101),
(303, 'Creative thinking', '2024-01-05', '2:00p.m. - 3:00p.m.', 'Dewan Rasah Prima', 27, 100),
(304, 'workshop1', '2024-03-13', '1:00p.m. - 3:00p.m.', 'Dewan', 27, 102),
(311, 'workshop 2', '2024-05-03', '2:00p.m. - 4:00p.m.', 'dewan1', 27, 101),
(312, 'Graphic Design Workshops', '2024-08-02', '11:00a.m. - 1:00p.m.', 'Meeting Room 1', 28, 100),
(313, 'workshop 1', '2024-06-04', '3:00p.m. - 4:00p.m.', 'DEwan', 20, 100);

-- --------------------------------------------------------

--
-- Table structure for table `eventsregistration`
--

CREATE TABLE `eventsregistration` (
  `Events_ID` int(11) NOT NULL,
  `Staff_ID` int(11) NOT NULL,
  `Attendance` int(3) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `eventsregistration`
--

INSERT INTO `eventsregistration` (`Events_ID`, `Staff_ID`, `Attendance`) VALUES
(301, 200, 0),
(303, 201, 1),
(301, 202, 1),
(301, 203, 1),
(302, 203, 1),
(303, 203, 1),
(301, 205, 1),
(303, 205, 1),
(304, 205, 1),
(311, 205, 0),
(301, 206, 0),
(302, 206, NULL),
(303, 206, 1),
(304, 206, NULL),
(311, 206, NULL),
(312, 206, NULL),
(303, 207, 1),
(311, 207, NULL),
(302, 211, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `staff`
--

CREATE TABLE `staff` (
  `Staff_ID` int(11) NOT NULL,
  `Staff_Name` varchar(50) NOT NULL,
  `Staff_Age` int(3) NOT NULL,
  `Staff_Gender` varchar(7) NOT NULL,
  `Staff_Tel` varchar(20) NOT NULL,
  `Staff_Password` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `staff`
--

INSERT INTO `staff` (`Staff_ID`, `Staff_Name`, `Staff_Age`, `Staff_Gender`, `Staff_Tel`, `Staff_Password`) VALUES
(200, 'Elly', 23, 'Female', '0128995058', 'E123'),
(201, 'kenny', 33, 'male', '0168990670', 'K123'),
(202, 'Aqilah', 25, 'female', '0167889393', 'Q123'),
(203, 'Wei Dong', 36, 'male', '0149446959', 'WD123'),
(205, 'Jun Ming', 44, 'male', '0165778439', 'JM123'),
(206, 'Anson Chong', 46, 'female', '0162776363', 'AAA123'),
(207, 'Aimi', 24, 'female', '0165447970', 'Am123'),
(208, 'Intan', 30, 'female', '0149885057', 'IT123'),
(211, 'Jing Ming', 23, 'female', '0167223839', 'dhgd '),
(212, 'employee', 34, 'male', '0163738274', 'hjk6785'),
(216, 'example', 23, 'male', '0145883940', 'abc123');

-- --------------------------------------------------------

--
-- Table structure for table `tutor`
--

CREATE TABLE `tutor` (
  `tutor_ID` int(11) NOT NULL,
  `Tutor_Name` varchar(50) NOT NULL,
  `Tutor_Age` int(3) NOT NULL,
  `Tutor_gender` varchar(7) NOT NULL,
  `Tutor_Tel` varchar(20) NOT NULL,
  `Tutor_Password` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `tutor`
--

INSERT INTO `tutor` (`tutor_ID`, `Tutor_Name`, `Tutor_Age`, `Tutor_gender`, `Tutor_Tel`, `Tutor_Password`) VALUES
(100, 'Jennifer Liew', 37, 'male', '0198875663', 'J123'),
(101, 'Chong Jia Wen', 35, 'female', '0167990885', 'JW123'),
(102, 'Alisah Binti ', 30, 'female', '0197665450', 'A123'),
(103, 'Kelisah', 40, 'female', '0145778980', '457j'),
(104, 'Jessy Lim', 30, 'female', '0146778670', 'JL123'),
(111, 'Washil bin Muhammad', 38, 'male', '0168994454', 'WM123'),
(112, 'Loww', 23, 'male', '0167774838', 'W123');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`admin_ID`),
  ADD UNIQUE KEY `Admin_ID` (`admin_ID`),
  ADD UNIQUE KEY `Admin_ID_2` (`admin_ID`),
  ADD UNIQUE KEY `Admin_ID_3` (`admin_ID`),
  ADD UNIQUE KEY `admin_ID_4` (`admin_ID`);

--
-- Indexes for table `events`
--
ALTER TABLE `events`
  ADD PRIMARY KEY (`Events_ID`),
  ADD UNIQUE KEY `Events_ID` (`Events_ID`),
  ADD KEY `Tutor_ID` (`Tutor_ID`);

--
-- Indexes for table `eventsregistration`
--
ALTER TABLE `eventsregistration`
  ADD PRIMARY KEY (`Staff_ID`,`Events_ID`),
  ADD KEY `Events_ID` (`Events_ID`);

--
-- Indexes for table `staff`
--
ALTER TABLE `staff`
  ADD PRIMARY KEY (`Staff_ID`);

--
-- Indexes for table `tutor`
--
ALTER TABLE `tutor`
  ADD PRIMARY KEY (`tutor_ID`),
  ADD UNIQUE KEY `tutor_ID` (`tutor_ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `admin`
--
ALTER TABLE `admin`
  MODIFY `admin_ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT for table `events`
--
ALTER TABLE `events`
  MODIFY `Events_ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=315;

--
-- AUTO_INCREMENT for table `staff`
--
ALTER TABLE `staff`
  MODIFY `Staff_ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=217;

--
-- AUTO_INCREMENT for table `tutor`
--
ALTER TABLE `tutor`
  MODIFY `tutor_ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=115;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `events`
--
ALTER TABLE `events`
  ADD CONSTRAINT `events_ibfk_1` FOREIGN KEY (`Tutor_ID`) REFERENCES `tutor` (`Tutor_ID`);

--
-- Constraints for table `eventsregistration`
--
ALTER TABLE `eventsregistration`
  ADD CONSTRAINT `eventsregistration_ibfk_1` FOREIGN KEY (`Staff_ID`) REFERENCES `staff` (`Staff_ID`),
  ADD CONSTRAINT `eventsregistration_ibfk_2` FOREIGN KEY (`Events_ID`) REFERENCES `events` (`Events_ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
