#include <stdio.h>
#include "mrt3fare.h"

char *mrt3_stations[MRT3_NUM_STATIONS] = {
	"North Ave (To Fernando Poe Jr.)",
	"Quezon Ave",
	"GMA Kamuning",
	"Cubao (To LRT2)",
	"Santolan Annapolis",
	"Ortigas",
	"Shaw Blvd",
	"Boni Ave",
	"Guadalupe",
	"Buendia",
	"Ayala",
	"Magallanes",
	"Taft Ave (To LRT1)"
};

int mrt3_fare_matrix[MRT3_NUM_STATIONS][MRT3_NUM_STATIONS] = {
		{ 0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28, 28 },  // North Ave
		{ 13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 24 },  // Quezon Ave
		{ 13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24 },  // GMA Kamuning
		{ 16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24 },  // Cubao Araneta
		{ 16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24 },  // Santolan Annapolis
		{ 20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 16, 20, 20 },  // Ortigas
		{ 20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20 },  // Shaw Blvd
		{ 20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 16 },  // Boni Ave
		{ 24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16 },  // Guadalupe
		{ 24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16 },  // Buendia
		{ 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13 },  // Ayala
		{ 28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13 },  // Magallanes
		{ 28, 28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0 }   // Taft Ave
};

int mrt3_sj_fare_matrix[MRT3_NUM_STATIONS][MRT3_NUM_STATIONS] = {
		{ 0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28, 28 },  // North Ave
		{ 13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 24 },  // Quezon Ave
		{ 13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24 },  // GMA Kamuning
		{ 16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24 },  // Cubao Araneta
		{ 16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24 },  // Santolan Annapolis
		{ 20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 16, 20, 20 },  // Ortigas
		{ 20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20 },  // Shaw Blvd
		{ 20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 16 },  // Boni Ave
		{ 24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16 },  // Guadalupe
		{ 24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16 },  // Buendia
		{ 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13 },  // Ayala
		{ 28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13 },  // Magallanes
		{ 28, 28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0 }   // Taft Ave
};
