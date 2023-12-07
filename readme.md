# Pharmaceutical Management System

## Group Members
- **Muhammad Owais Muhammad Rafiq** (23K-2042)
- **Syed Umer Taiyab** (23K-2016)
- **Abubakar Bin Hassan** (23K-2025)

## Introduction

The **Pharmaceutical Management System** project aims to revolutionize day-to-day pharmacy operations by introducing an efficient and automated system. The system addresses challenges faced by pharmacists, such as manual stock monitoring, tracking expiration dates, and order placement. By automating these tasks, the system saves time, reduces errors, and enhances overall efficiency. Key features include a centralized medicine database, seamless order placement, receipt generation, and intelligent alerts for expiry dates and low stock levels. The goal is to streamline pharmacy management for a more accurate and timely response to inventory needs.

## Background

The decision to develop the Pharmaceutical Management System arises from inefficiencies observed in manual systems used in foreign pharmacies. Manual stock checks lead to delays, errors, and a lack of proactive management. The project draws inspiration from successful pharmacy systems abroad while addressing specific challenges faced by local pharmacies. The system leverages automation and user-friendly interfaces to bring a positive transformation to pharmaceutical management.

## Project Specification

The Pharmaceutical Management System includes features such as detailed medicine information, order placement, receipt generation, and stock tracking. It supports two login IDs for administrators and pharmacists, ensuring secure access. A public ID allows customer feedback, and a bug reporting mechanism enhances continuous improvement. Leveraging the C programming language on the Windows platform, the system aims for a robust and user-friendly platform, reducing manual workload.

## Problem Analysis

The existing manual system for checking medicine stock is time-consuming and error-prone. Manual stock checks lead to delayed services and potential errors. The need for an automated solution is evident to address these challenges and improve overall pharmacy management.

## Solution Design

The proposed Pharmaceutical Management System automates stock management, order processes, and enhances efficiency. Features include detailed medicine records, order processing, receipt generation, and dual login IDs. The system incorporates a public ID for customer feedback, bug reporting, and intelligent alert systems for expiry dates and low stock levels. The design focuses on a seamless and error-free operation.

## Implementation and Testing

Challenges faced during implementation include the login function, handling fgets(), and implementing the update function. The project breakdown structure outlines individual contributions, including login functions, bug reporting, order history, and receipt printing.

## Project Breakdown Structure

## Owais
1. Starting of the pharmacist code by making the main function. (17-Nov)
2. Implemented the login function and replaced the password line with steric (*) (20-Nov)
3. Revised the login function with assistance from Umer. (21-Nov)
4. Finalized the decision on what functions the pharmacist's side must have and started on the ordering function, allowing users to input new medicines' information into the system. (23-Nov)
5. Implemented the bug reporting function where pharmacists can report bugs to the admin, and the report will be sent to the admin along with real-time information imported through the time.h library. (24-Nov)
6. Implemented the print_stock function to display detailed information about medicines, and the location display function allows pharmacists to see the location of each medicine. (26-Nov)
7. Implemented the update function, enabling pharmacists to update the stock of existing medicines. (30-Nov)

## Abubakar
1. Made the customer function, including the review functionality that writes to the reviews file. (15-Nov)
2. Implemented the use of timestring in the review part of the code using the functionality provided by the time.h library. (17-Nov)
3. Started on the customer_order function, taking name input from the customer, and working on storing orders. (20-Nov)
4. Implemented the array (medicine) to use it for the receipt and order history. (23-Nov)
5. Implemented the logic behind the array (iterating 2 times) with assistance from Umer. (27-Nov)
6. Implemented the order history and current order file writing functionality. (30-Nov)
7. Finalized the receipt printing functionality and wrapped up the customer side. (4-Dec)

## Umer
1. Started the admin side code. (18-Nov)
2. Implemented the login function on the admin side and assisted in the revision of the pharmacist login function. (21-Nov)
3. Implemented the function to read the bug report left by the pharmacist in his side of the code. (25-Nov)
4. Implemented the functionality to read the reviews left on the customer side. (28-Nov)
5. Implemented the function to change passwords for both pharmacist and admin, and revised the login functions to use filing. (30-Nov)
6. Implemented the order history function. (30-Nov)
7. Assisted Abubakar in implementing the pharmacist order history code on both the customer side and pharmacist side. (3-Dec)
8. Did a final revision on the three different codes and then compiled them into a single C file. (5-Dec)


## Conclusion

In conclusion, the Pharmaceutical Management System offers a revolutionary solution to traditional pharmacy management. Leveraging automation and technology, the system addresses inefficiencies in manual systems, ensuring a streamlined workflow. With features like comprehensive medicine records, order processing, and customer feedback mechanisms, the system sets the stage for improved pharmaceutical management. Utilizing the C programming language and operating on the Windows platform aligns the project with industry standards, making it a practical and user-friendly solution. The system enhances efficiency, accuracy, and reliability in pharmaceutical management processes.
