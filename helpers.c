#include "helpers.h"
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float new1 = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            int new2 = (int) round(new1);
            image[i][j].rgbtRed = new2;
            image[i][j].rgbtGreen = new2;
            image[i][j].rgbtBlue = new2;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float newred1 = ((0.393 * (image[i][j].rgbtRed)) + (0.769 * (image[i][j].rgbtGreen)) +
                             (0.189 * (image[i][j].rgbtBlue)));
            int newred2 = (int) round(newred1);
            if (newred2 > 255)
            {
                newred2 = 255;
            }

            float newgreen1 = (0.349 * (image[i][j].rgbtRed)) + (0.686 * (image[i][j].rgbtGreen)) +
                              (0.168 * (image[i][j].rgbtBlue));
            int newgreen2 = (int) round(newgreen1);
            if (newgreen2 > 255)
            {
                newgreen2 = 255;
            }

            float newblue1 = ((0.272 * (image[i][j].rgbtRed)) + (0.534 * (image[i][j].rgbtGreen)) +
                              (0.131 * (image[i][j].rgbtBlue)));
            int newblue2 = (int) round(newblue1);
            if (newblue2 > 255)
            {
                newblue2 = 255;
            }
            image[i][j].rgbtRed = newred2;
            image[i][j].rgbtGreen = newgreen2;
            image[i][j].rgbtBlue = newblue2;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int remain = (width % 2);
    if (remain == 0)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0, nwidth = ((width / 2)); j < nwidth; j++)
            {
                RGBTRIPLE tmp = image[i][j];
                image[i][j] = image[i][width - 1 - j];
                image[i][width - 1 - j] = tmp;
            }
        }
    }
    else if (remain == 1)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0, nwidth = ((width - 1) / 2); j < nwidth; j++)
            {
                RGBTRIPLE tmp = image[i][j];
                image[i][j] = image[i][width - 1 - j];
                image[i][width - 1 - j] = tmp;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum1 = 0;
            int sum2 = 0;
            int sum3 = 0;
            float squares = 1.0;
            int avrg1 = 0;
            int avrg2 = 0;
            int avrg3 = 0;
            int width1 = width - 1;
            int height1 = height - 1;

            if (i == 0) // first row
            {
                for (int a = 0, b = 2; a < b; a++)
                {
                    if (j > 0) // first row and not first column
                    {
                        if (j < width1) // first row and not last column
                        {
                            squares = 6.0;
                            for (int k = (j - 1), limit1 = (j + 2); k < limit1; k++)
                            {
                                sum1 += copy[a][k].rgbtRed;
                                sum2 += copy[a][k].rgbtGreen;
                                sum3 += copy[a][k].rgbtBlue;
                            }
                        }
                        else if (j == width1) // first row last column
                        {
                            squares = 4.0;
                            for (int k = (width1 - 1); k < width; k++)
                            {
                                sum1 += copy[a][k].rgbtRed;
                                sum2 += copy[a][k].rgbtGreen;
                                sum3 += copy[a][k].rgbtBlue;
                            }
                        }
                    }
                    else if (j == 0) // first row first column
                    {
                        squares = 4.0;
                        for (int k = 0; k < 2; k++)
                        {
                            sum1 += copy[a][k].rgbtRed;
                            sum2 += copy[a][k].rgbtGreen;
                            sum3 += copy[a][k].rgbtBlue;
                        }
                    }
                }
            }

            else if (i > 0) // all other rows and last row
            {
                if (i == height1) // last row
                {
                    for (int a = (height1 - 1), b = height; a < b; a++)
                    {
                        if (j > 0) // last row and not first column
                        {
                            if (j < width1) // last row and not last column
                            {
                                squares = 6.0;
                                for (int k = (j - 1), limit1 = (j + 2); k < limit1; k++)
                                {
                                    sum1 += copy[a][k].rgbtRed;
                                    sum2 += copy[a][k].rgbtGreen;
                                    sum3 += copy[a][k].rgbtBlue;
                                }
                            }
                            else if (j == width1) // last row last column
                            {
                                squares = 4.0;
                                for (int k = (width1 - 1); k < width; k++)
                                {
                                    sum1 += copy[a][k].rgbtRed;
                                    sum2 += copy[a][k].rgbtGreen;
                                    sum3 += copy[a][k].rgbtBlue;
                                }
                            }
                        }
                        else if (j == 0) // last row first column
                        {
                            squares = 4.0;
                            for (int k = 0; k < 2; k++)
                            {
                                sum1 += copy[a][k].rgbtRed;
                                sum2 += copy[a][k].rgbtGreen;
                                sum3 += copy[a][k].rgbtBlue;
                            }
                        }
                    }
                }
                else if (j == 0) // first column edge
                {
                    squares = 6.0;
                    for (int a = (i - 1), b = (i + 2); a < b; a++)
                    {
                        for (int k = 0, c = 2; k < c; k++)
                        {
                            sum1 += copy[a][k].rgbtRed;
                            sum2 += copy[a][k].rgbtGreen;
                            sum3 += copy[a][k].rgbtBlue;
                        }
                    }
                }
                else if (j == width1) // last column edge
                {
                    squares = 6.0;
                    for (int a = (i - 1), b = (i + 2); a < b; a++)
                    {
                        for (int k = (height1 - 1); k < height; k++)
                        {
                            sum1 += copy[a][k].rgbtRed;
                            sum2 += copy[a][k].rgbtGreen;
                            sum3 += copy[a][k].rgbtBlue;
                        }
                    }
                }
                else
                {
                    squares = 9.0;
                    for (int k = i - 1, limit1 = (i + 2); k < limit1; k++)
                    {
                        for (int m = j - 1, limit2 = (j + 2); m < limit2; m++)
                        {
                            sum1 += copy[k][m].rgbtRed;
                            sum2 += copy[k][m].rgbtGreen;
                            sum3 += copy[k][m].rgbtBlue;
                        }
                    }
                }
            }
            avrg1 = round(sum1 / (squares));
            avrg2 = round(sum2 / (squares));
            avrg3 = round(sum3 / (squares));
            image[i][j].rgbtRed = avrg1;
            image[i][j].rgbtGreen = avrg2;
            image[i][j].rgbtBlue = avrg3;
        }
    }
}
