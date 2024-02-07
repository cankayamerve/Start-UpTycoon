#ifndef SPECIALITY_H
#define SPECIALITY_H

/**
 * @file
 * @brief Defines the Speciality enumeration.
 */

/**
 * @brief Enumeration representing different specialties.
 *
 * This enumeration lists various specialities related to software development or IT fields.
 * It includes options like Game Development, Front-end Development, Back-end Development,
 * Data Science, Cybersecurity, and AI (Artificial Intelligence).
 */
enum Speciality {
    Game_spc,    /**< Represents Game Development specialization. */
    Front_end,   /**< Represents Front-end Development specialization. */
    Back_end,    /**< Represents Back-end Development specialization. */
    Data_sci,    /**< Represents Data Science specialization. */
    Cyber_sec,   /**< Represents Cybersecurity specialization. */
    Ai,          /**< Represents Artificial Intelligence (AI) specialization. */
    Num_Specialities /**< Represents the count of specialities in the enumeration. */
};

#endif // SPECIALITY_H
