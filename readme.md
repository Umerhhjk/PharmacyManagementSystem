<style>
  strong{
    font-size: 12px;
  }
</style>

<strong>Group Members</strong><br><br>
23K-2042 Muhammad Owais Muhammad Rafiq<br>
23K-2016 Syed Umer Taiyab<br>
23K-2025 Abubakar Bin Hassan<br><br>
<strong>Introduction (Aim or Motivation):</strong><br><br>
The aim of our Pharmaceutical Management System project is to revolutionize the day-to-day operations of pharmacies by introducing an efficient and automated system. Recognizing the challenges faced by pharmacists in manually monitoring stock levels, tracking expiration dates, and placing orders, our system proposes a comprehensive solution. By automating these tasks, we intend to save valuable time, reduce human errors, and enhance overall operational efficiency. The system will not only provide a centralized database of medicines but also enable seamless order placement, receipt generation, and stock monitoring. The introduction of features like expiry date alerts and low stock warnings will significantly improve decision-making processes for pharmacists. The ultimate goal is to streamline pharmacy management, ensuring a more accurate and timely response to inventory needs.<br><br>
<strong>Background (Research & Project Selection):</strong><br><br>
The decision to develop a Pharmaceutical Management System stems from the observation of inefficiencies in the current manual systems, particularly those used in foreign pharmacies. The existing reliance on manual stock checks often leads to delays, errors, and a lack of proactive management. Through preliminary research, we identified the need for an integrated system that not only provides real-time information on medicine stock but also facilitates streamlined processes such as ordering, receipt generation, and location tracking within the pharmacy. This project draws inspiration from successful pharmacy systems in foreign countries while aiming to address the specific challenges faced by local pharmacies. By harnessing the power of automation and incorporating user-friendly interfaces, we aspire to bring about a positive transformation in the pharmaceutical management landscape.<br><br>
<strong>Project Specification:</strong><br><br>
Our Pharmaceutical Management System is designed to encompass a range of features tailored to the unique needs of pharmacies. These include the ability to retrieve detailed information about medicines, add new records, place orders, generate receipts, and track stock levels. The system will support two distinct login IDs, one for administrators and another for pharmacists, ensuring secure access and accountability. Additionally, a public ID will be introduced for customer feedback, fostering a more customer-centric approach. The system will also feature a bug reporting mechanism to enhance continuous improvement. By leveraging the C programming language and operating on Windows, we aim to create a robust and user-friendly platform that streamlines pharmacy operations, ultimately enhancing efficiency and reducing manual workload.<br><br>
<strong>Problem Analysis:</strong><br><br>
The existing manual system of checking medicine stock is identified as a time-consuming and error-prone process. Pharmacists face challenges in locating medicines and often discover low stock levels only through physical checks. These inefficiencies can lead to delayed services and potential human errors. The need for an automated solution becomes apparent in addressing these challenges and improving overall pharmacy management.<br><br>
<strong>Solution Design (Project Detail, Functionality, and Features):</strong><br><br>
The proposed Pharmaceutical Management System seeks to automate stock management, order processes, and enhance overall efficiency. Features include detailed medicine records with information such as ID, cost, selling price, expiry date, supplier details, and current stock levels. The system allows for adding new information to the records, ordering medicines, generating receipts, and offers two distinct login IDs for administrative and pharmacist roles. Additionally, it incorporates a public ID for customer feedback, bug reporting, and a logout feature for security. Intelligent alert systems warn about impending expiry dates and low stock levels, while a purchasing power calculation feature provides financial insights. The system's functionality is tailored to meet the diverse needs of pharmacy management, aiming for a seamless and error-free operation.<br><br>
<strong>Implementation and Testing:</strong><br><br>
•	Faced challenges in implementing the login function, finally did it through the getch() function. <br>
•	Faced challenge in fgets() as it did not work as intended and used a workaround in scanf and predetermined reviews. <br>
•	Had a hard time in implementing the update function to update stock.  <br><br>
<strong>Project Breakdown Structure:</strong><br><br>
<strong>Owais</strong><br> 
1.	Starting of the pharmacist code by making the main function. 17-Nov <br>
2.	Implemented the login function and replacing password line with steric (*) 20-Nov <br>
3.	Revised the login function with assistance from Umer. 21-Nov <br>
4.	Finalized the decision on what functions the pharmacists side must have and started on the ordering function in which user is enable to push their new medicines information into the system. 23-Nov <br>
5.	Implemented the bug reporting function where pharmacist can report the bug to the admin and the report will be send to admin along with the real time imported through the library of time.h . 24-Nov <br>
6.	Implemented the print_stock in which it display each and every information of the medicines and location display function in which pharmacist can see the location of each and every medicines. 26-Nov <br>
7.	Implemented the update function in which pharmacist can update the stock of the existed medicines. 30-Nov <br><br>

<strong>Abubakar</strong><br>
1.	Made the customer function (made the review functionality, which writes to the reviews file). 15-Nov <br>
2.	Implemented the use of timestring in the review part of the code using the functionality provided by time.h library. 17-Nov <br>
3.	Started on the customer_order function with taking name input from customer and working on storing orders. 20-Nov <br>
4.	Implemented the array(medicine) to use it for the reciept and order history. 23-Nov <br>
5.	Implemented the logic behind array(iterating 2 times) with assist from umer. 27-Nov <br>
6.	Implemented the order history, current order file writing functionality. 30-Nov <br>
7.	Finalized the reciept printing functionality and wrapped up the customer side. 4-Dec <br><br> 

<strong>Umer </strong><br>
1.	Started the admin side code. 18-Nov <br>
2.	Implemented the login function on admin side and assisted in revision of the pharmacist login function. 21-Nov <br>
3.	Implemented the function to read the bug report left by the pharmacist in his side of code. 25-Nov <br>
4.	Implemented the functionality to read the reviews left on the customer side. 28-Nov <br>
5.	Implemented the function to change passwords of both pharmacist and admin, and revised the login functions to use filing. 30-Nov <br>
6.	Implemented the order history function. 30-Nov <br>
7.	Assisted Abubakar in implementing the pharmacist order history code on both customer side and pharmacist side. 3-Dec <br>
8.	Did a final revision on the three different codes and then compiled them into a single C file. 5-Dec <br><br>

