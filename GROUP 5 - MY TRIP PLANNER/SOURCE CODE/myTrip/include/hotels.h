#ifndef DESTINATIONS_H
#define DESTINATIONS_H

int addNewHotels(char, int, int);
void displayHotelDetails();
int writeToHotelsFile();
int displayHotelsFileData();
void modifyHotelDetails(char hotelName, int fare, int rating);
int insertModifiedHotelData();
int deleteHotel(char);
#endif
