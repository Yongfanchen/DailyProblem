#ifndef __D3PLOTREADER_H__
#define __D3PLOTREADER_H__

#ifdef WIN32

#if defined (LSREADER_CXX_STATIC_LIB)
#define READERAPI
#else
#if defined (lsreader_cxx_EXPORTS)
#define READERAPI __declspec(dllexport)
#else // outside DLL
#define READERAPI __declspec(dllimport)
#endif
#endif

#else
#define READERAPI
#endif

#ifndef WIN32
#include <stdint.h>
typedef int64_t D3P_INTEGER_64;
#else
typedef __int64 D3P_INTEGER_64;
#endif

#if defined (__X64__)
typedef D3P_INTEGER_64 D3P_INT64;
#else
typedef unsigned long D3P_INT64;
#endif

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

#define LSREADER_VERSION "0.1.47"

#ifndef __D3P_RETURN_TYPE_ENUMERATIONS__
#define __D3P_RETURN_TYPE_ENUMERATIONS__
enum D3P_ReturnType {
    /**
     * Input was as expected, output is as expected
     */
    D3P_SUCCESS=1,
	/**
	 * General error
	 */
	D3P_ERROR,
    /**
     * Parameter error
     */
    D3P_ERROR_PARAMETER,
    /**
     * Failed to read file
     */
    D3P_ERROR_FREAD,
    /**
     * No data in database
     */
    D3P_WARNING_NO_DATA,
    /**
     * The type of element doesn't exist for current model.
     */
    D3P_WARNING_NO_ELEM,
};
#endif

#ifndef __D3P_MESSAGE_TYPE_ENUMERATIONS__
#define __D3P_MESSAGE_TYPE_ENUMERATIONS__
enum D3P_MessageType {
    /**
     * Do not print information
     */
    D3P_MESSAGE_OFF,
	/**
	 * Print brief information
	 */
	D3P_MESSAGE_DEBUG,
	/**
	 * Print verbose information
	 */
	D3P_MESSAGE_VERBOSE,
};
#endif

#ifndef __D3P_DATA_TYPE_ENUMERATIONS__
#define __D3P_DATA_TYPE_ENUMERATIONS__

enum D3P_DataType
{
/*==================== D3plot begin ====================*/
    /**
     * conversion: char[]
     * length    : 80
     * parameters: ignore
     */
    D3P_CODE_RELEASE,
	/**
	 * conversion: char[]
     * length    : 80
	 * parameters: ignore
	 */
	D3P_TITLE,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_RIGID_BODY_SHELL_ELEMENT,

    //INQUIRY FUNCTION
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_D3PLOT,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_FEMZIP,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_GLOBAL_KINETIC_ENERGY,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_GLOBAL_INTERNAL_ENERGY,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_GLOBAL_TOTAL_ENERGY,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_GLOBAL_VELOCITY,

	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_PART_TITLE,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore, ist if adaptive
	 */
	D3P_HAS_PART_IDS,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_PART_NAME,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_PART_NAME_STRUCT,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_PART_INTERNAL_ENERGY,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_PART_KINETIC_ENERGY,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_PART_VELOCITY,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_PART_MASS,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_PART_HOURGLASS,

	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_RIGID_WALL_FORCE,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_RIGID_WALL_POSITION,

    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_IS_ADAPTIVE,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_IDS,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_THERMAL_STRAIN,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_PLASTIC_STRAIN,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_STRAIN,

    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_TEMPERATURE,
    /**
     * conversion: int
     * length    : 1
     * parameters: ignore
     */
    D3P_NUM_TEMPERATURE,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_HEAT_FLUX,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_NODE_IDS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_NODE_COORDINATES,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_NODE_VELOCITIES,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_NODE_ACCELERATIONS,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_NODE_MASS_SCALING,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_NODE_TEMPERATURE_DIVIDE_TIME,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_NODE_RESIDUAL_FORCE,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_NODE_RESIDUAL_MOMENT,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_NODE_PENETRATION,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_NODE_RELATIVE_PENETRATION,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_NODE_CONTACT_ENERGY_DENSITY,

	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SOLID_IDS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SOLID_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SOLID_VON_MISES_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SOLID_EFFECTIVE_PLASTIC_STRAIN,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SOLID_STRAIN,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SOLID_STRAIN_RATE,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SOLID_PLASTIC_STRAIN,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SOLID_THERMAL_STRAIN,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SOLID_HISTORY_VAR,

    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_TSHELL_IDS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_TSHELL_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_TSHELL_VON_MISES_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_TSHELL_EFFECTIVE_PLASTIC_STRAIN,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_TSHELL_STRAIN,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_TSHELL_STRAIN_RATE,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_TSHELL_HISTORY_VAR,

	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_BEAM_IDS,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_BEAM_AXIAL_FORCE,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_BEAM_S_SHEAR_RESULTANT,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_BEAM_T_SHEAR_RESULTANT,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_BEAM_S_BENDING_MOMENT,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_BEAM_T_BENDING_MOMENT,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_BEAM_TORSIONAL_RESULTANT,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_BEAM_AXIAL_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_BEAM_RS_SHEAR_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_BEAM_TR_SHEAR_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_BEAM_AXIAL_PLASTIC_STRAIN,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_BEAM_AXIAL_STRAIN,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_BEAM_HISTORY_VAR,

	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_SHELL_IDS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_SHELL_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_SHELL_VON_MISES_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_SHELL_EFFECTIVE_PLASTIC_STRAIN,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_SHELL_STRAIN,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_SHELL_STRAIN_RATE,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_SHELL_PLASTIC_STRAIN,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_SHELL_THERMAL_STRAIN,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_THICKNESS,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SHELL_THICKNESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SHELL_ELEMENT_DEPENDENT_VAR_1,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SHELL_ELEMENT_DEPENDENT_VAR_2,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_SHELL_HISTORY_VAR,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_SHELL_MX,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_SHELL_MY,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_SHELL_MXY,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_SHELL_QX,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_SHELL_QY,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_SHELL_NX,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_SHELL_NY,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_SHELL_NXY,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore, ist if adaptive model
     */
    D3P_HAS_SHELL_INTERNAL_ENERGY_DENSITY,
	
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SPH_RAIDUS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SPH_PRESSURE,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SPH_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SPH_VON_MISES_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SPH_PLASTIC_STRAIN,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SPH_DENSITY,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SPH_INTERNAL_ENERGY,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SPH_STRAIN,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SPH_STRAIN_RATE,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_SPH_MASS,

    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_FREQUENCY,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_FREQUENCY_HAS_NODE_DISPLACEMENTS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_FREQUENCY_HAS_NODE_VELOCITIES,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_NODE_ACCELERATIONS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_SOLID_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_SOLID_VON_MISES_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_SOLID_STRAIN,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_TSHELL_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_TSHELL_VON_MISES_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_TSHELL_STRAIN,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_BEAM_AXIAL_FORCE,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_BEAM_S_SHEAR_RESULTANT,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_BEAM_T_SHEAR_RESULTANT,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_BEAM_S_BENDING_MOMENT,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_BEAM_T_BENDING_MOMENT,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_BEAM_TORSIONAL_RESULTANT,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_BEAM_AXIAL_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_BEAM_RS_SHEAR_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_BEAM_TR_SHEAR_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_BEAM_AXIAL_PLASTIC_STRAIN,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_BEAM_AXIAL_STRAIN,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_SHELL_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_SHELL_VON_MISES_STRESS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_FREQUENCY_HAS_SHELL_STRAIN,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_FTG,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_FTG_HAS_SOLID_VARIABLES,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_FTG_HAS_TSHELL_VARIABLES,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_FTG_HAS_BEAM_VARIABLES,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_FTG_HAS_SHELL_VARIABLES,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_ACS,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ACS_HAS_ACOUSTIC_PRESSURE_REAL,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ACS_HAS_ACOUSTIC_PRESSURE_IMAGINARY,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ACS_HAS_ACOUSTIC_INTENSITY,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ACS_HAS_SOUND_PRESSURE_LEVEL_dB,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ACS_HAS_NORMAL_VELOCITY_REAL,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ACS_HAS_NORMAL_VELOCITY_IMAGINARY,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_ATV,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ATV_HAS_ACOUSTIC_PRESSURE_REAL,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ATV_HAS_ACOUSTIC_PRESSURE_IMAGINARY,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ATV_HAS_SOUND_PRESSURE_LEVEL_dB,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_HAS_EIGV,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_EIGV_HAS_NODE_COORDINATES,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_EIGV_HAS_NODE_VELOCITIES,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_EIGV_HAS_NODE_ACCELERATIONS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_EIGV_AC,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_EIGV_AC_HAS_ACOUSTIC_PRESSURE_REAL,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_ERP,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ERP_HAS_NORMAL_VELOCITY_REAL,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ERP_HAS_NORMAL_VELOCITY_IMAGINARY,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ERP_HAS_NORMAL_VELOCITY_ABSOLUTE,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ERP_HAS_ACOUSTIC_INTENSITY,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ERP_HAS_ACOUSTIC_ERP_DENSITY,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_ACP,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ACP_HAS_ACOUSTIC_PRESSURE_REAL,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ACP_HAS_ACOUSTIC_PRESSURE_IMAGINARY,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ACP_HAS_ACOUSTIC_INTENSITY,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ACP_HAS_SOUND_PRESSURE_LEVEL_dB,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_ACC,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_ACC_HAS_FIELD_POINT,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_ACC_HAS_SHELL_VARIABLES,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_ALE,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_2D_ALE,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_ALE_HAS_MATERIAL_IDS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_ALE_HAS_DENSITY,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_ALE_HAS_VOLUME_FRACTION,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_ALE_HAS_DOMINANT_MATERIAL,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_ALE_HAS_SPECIES_MASS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_2D_ALE_HAS_DENSITY,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_2D_ALE_HAS_VOLUME_FRACTION,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_2D_ALE_HAS_DOMINANT_MATERIAL,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_2D_ALE_HAS_SPECIES_MASS,


    /**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
    D3P_HAS_MS_DATA,
    /**
     * conversion: bool
     * length    : 1
     * parameters: index_multisolver, ipart
     */
	D3P_MS_DOMAIN_HAS_PART_NAME,
    /**
     * conversion: bool
     * length    : 1
     * parameters: index_multisolver
     */
	D3P_MS_DOMAIN_HAS_PART_MAT,
    /**
     * conversion: bool
     * length    : 1
     * parameters: index_multisolver
     */
	D3P_MS_DOMAIN_HAS_PART_IDS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: index_multisolver
     */
	D3P_MS_DOMAIN_HAS_NODE_IDS,
    /**
     * conversion: bool
     * length    : 1
     * parameters: index_multisolver
     */
	D3P_MS_DOMAIN_HAS_ELEM_IDS,

    /**
     * conversion: bool
     * length    : 1
     * parameters: ipart_user or ipart
     */
    D3P_IS_SHELL,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ipart_user or ipart
     */
    D3P_IS_SOLID,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ipart_user or ipart
     */
    D3P_IS_TSHELL,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ipart_user or ipart
     */
    D3P_IS_BEAM,
    /**
     * conversion: bool
     * length    : 1
     * parameters: ipart_user or ipart
     */
    D3P_IS_SPH,
	/**
     * conversion: bool
     * length    : 1
     * parameters: ignore
     */
	D3P_IS_COMPLEX_D3SSD,

	//STATE BLOCK
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_STATES,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: ignore
	 */
	D3P_TIMES,
    /**
     * conversion: int
     * length    : 1
     * parameters: ist
     */
    D3P_NEW_GEOM,
    /**
     * conversion: int
     * length    : 1
     * parameters: ist
     */
    D3P_NEW_GEOM_STATE,
	/**
	 * conversion: float
	 * length    : 1
	 * parameters: ist
	 */
	D3P_GLOBAL_KINETIC_ENERGY,
	/**
	 * conversion: float
	 * length    : 1
	 * parameters: ist
	 */
	D3P_GLOBAL_INTERNAL_ENERGY,
	/**
	 * conversion: float
	 * length    : 1
	 * parameters: ist
	 */
	D3P_GLOBAL_TOTAL_ENERGY,
	/**
	 * conversion: D3P_Vector
	 * length    : 1
	 * parameters: ist
	 */
	D3P_GLOBAL_VELOCITY,
	
	//PART
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_PARTS,
	/**
	 * conversion: int
	 * length    : D3P_NUM_PARTS
	 * parameters: ignore
	 */
	D3P_PART_IDS,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_PART_NAME,
    /**
	 * conversion: char
	 * length    : 80
	 * parameters: ipart_user or ipart
	 */
	D3P_PART_NAME,
	/**
	 * conversion: D3P_PartTitle
	 * length    : D3P_NUM_PART_NAME
	 * parameters: ignore
	 */
	D3P_PART_NAME_STRUCT,
	/**
	 * conversion: float
	 * length    : 1
	 * parameters: ist, ipart_user or ipart
	 */
	D3P_PART_INTERNAL_ENERGY,
	/**
	 * conversion: float
	 * length    : 1
	 * parameters: ist, ipart_user or ipart
	 */
	D3P_PART_KINETIC_ENERGY,
	/**
	 * conversion: D3P_Vector
	 * length    : 1
	 * parameters: ist, ipart_user or ipart
	 */
	D3P_PART_VELOCITY,
	/**
	 * conversion: float
	 * length    : 1
	 * parameters: ist, ipart_user or ipart
	 */
	D3P_PART_MASS,
	/**
	 * conversion: float
	 * length    : 1
	 * parameters: ist, ipart_user or ipart
	 */
	D3P_PART_HOURGLASS,
    /**
	 * conversion: int
	 * length    : 1
	 * parameters: iuser
	 */
	D3P_PART_INTERNAL_ID,

	//RIGID WALL
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore, ist if adaptive model
	 */
	D3P_NUM_RIGID_WALL,
	/**
	 * conversion: float
	 * length    : 1
	 * parameters: ist, i_rigid_wall
	 */
	D3P_RIGID_WALL_FORCE,
	/**
	 * conversion: D3P_Vector
	 * length    : 1
	 * parameters: ist, i_rigid_wall
	 */
	D3P_RIGID_WALL_POSITION,
		
	//NODE
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NUM_NODES,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_NODES
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NODE_INITIAL_COORDINATES,
	/**
	 * conversion: D3P_VectorDouble
	 * length    : D3P_NUM_NODES
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NODE_INITIAL_COORDINATES_DOUBLE,
	/**
	 * conversion: int
	 * length    : D3P_NUM_NODES
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NODE_IDS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_NODES
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set, ipt if necessary
                   shell node:
                   ipt = 0, middle
                   ipt = 1, inner
                   ipt = 2, outer
                   solid node: ignore
	 */
	D3P_NODE_TEMPERATURE,
	/**
	 * conversion: double
	 * length    : D3P_NUM_NODES
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set, ipt if necessary
                   shell node:
                   ipt = 0, middle
                   ipt = 1, inner
                   ipt = 2, outer
                   solid node: ignore
	 */
	D3P_NODE_TEMPERATURE_DOUBLE,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_NODES
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NODE_HEAT_FLUX,
	/**
	 * conversion: float
	 * length    : D3P_NUM_NODES
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NODE_MASS_SCALING,
	/**
	 * conversion: float
	 * length    : D3P_NUM_NODES
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NODE_TEMPERATURE_DIVIDE_TIME,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_NODES
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NODE_RESIDUAL_FORCE,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_NODES
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NODE_RESIDUAL_MOMENT,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_NODES
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NODE_PENETRATION,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_NODES
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NODE_RELATIVE_PENETRATION,
	/**
	 * conversion: float
	 * length    : D3P_NUM_NODES
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NODE_CONTACT_ENERGY_DENSITY,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_NODES
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NODE_COORDINATES,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_NODES
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NODE_VELOCITIES,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_NODES
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NODE_ACCELERATIONS,
    /**
	 * conversion: D3P_VectorDouble
	 * length    : D3P_NUM_NODES
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NODE_COORDINATES_DOUBLE,
	/**
	 * conversion: D3P_VectorDouble
	 * length    : D3P_NUM_NODES
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NODE_VELOCITIES_DOUBLE,
	/**
	 * conversion: D3P_VectorDouble
	 * length    : D3P_NUM_NODES
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NODE_ACCELERATIONS_DOUBLE,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: iuser
	 */
	D3P_NODE_INTERNAL_ID,
	
	//SOLID
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NUM_SOLID,
    /**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_SOLID_PART,
	/**
	 * conversion: D3P_Solid
	 * length    : D3P_NUM_SOLID
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_CONNECTIVITY_MAT,
	/**
	 * conversion: int
	 * length    : D3P_NUM_SOLID
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_IDS,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipt if necessary, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipt if necessary, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_VON_MISES_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipt if necessary, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_SIGNED_VON_MISES_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipt if necessary, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_1ST_PRINCIPAL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipt if necessary, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_2ND_PRINCIPAL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipt if necessary, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_3RD_PRINCIPAL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipt if necessary, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_TRESCA_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipt if necessary, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_EFFECTIVE_PLASTIC_STRAIN,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_VON_MISES_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_SIGNED_VON_MISES_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_MAX_PRINCIPAL_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_2ND_PRINCIPAL_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_MIN_PRINCIPAL_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_TRESCA_STRAIN,
    /**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
    D3P_SOLID_PLASTIC_STRAIN,
    /**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
    D3P_SOLID_THERMAL_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipt if necessary, ihv, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_HISTORY_VAR,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_SOLID_MAXINT,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: iuser
	 */
	D3P_SOLID_INTERNAL_ID,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_SOLID_HISTORY_VAR_NUM,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_ELEMENT_CENTROID,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ist
	 */
	D3P_NUM_SOLID20,
	/**
	 * conversion: D3P_SolidExtra20
	 * length    : D3P_NUM_SOLID20
	 * parameters: ist
	 */
	D3P_SOLID20_CONNECTIVITY_EXTRA,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ist
	 */
	D3P_NUM_SOLID27,
	/**
	 * conversion: D3P_SolidExtra27
	 * length    : D3P_NUM_SOLID27
	 * parameters: ist
	 */
	D3P_SOLID27_CONNECTIVITY_EXTRA,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_INFINITESIMAL_STRAIN,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_GREEN_STRAIN,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_ALMANSI_STRAIN,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SOLID_STRAIN_RATE,
	
	//TSHELL
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NUM_TSHELL,
    /**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_TSHELL_PART,
	/**
	 * conversion: D3P_Tshell
	 * length    : D3P_NUM_TSHELL
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_TSHELL_CONNECTIVITY_MAT, 
	/**
	 * conversion: int
	 * length    : D3P_NUM_TSHELL
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_TSHELL_IDS,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_TSHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_TSHELL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_TSHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_TSHELL_VON_MISES_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_TSHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_TSHELL_SIGNED_VON_MISES_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_TSHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_TSHELL_1ST_PRINCIPAL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_TSHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_TSHELL_2ND_PRINCIPAL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_TSHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_TSHELL_3RD_PRINCIPAL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_TSHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_TSHELL_TRESCA_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_TSHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_TSHELL_EFFECTIVE_PLASTIC_STRAIN,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_TSHELL
     * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
                   ipt = 0: middle
                   ipt = 1: inner
                   ipt = 2: outer
	 */
	D3P_TSHELL_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_TSHELL
     * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
                   ipt = 0: middle
                   ipt = 1: inner
                   ipt = 2: outer
	 */
	D3P_TSHELL_VON_MISES_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_TSHELL
     * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
                   ipt = 0: middle
                   ipt = 1: inner
                   ipt = 2: outer
	 */
	D3P_TSHELL_SIGNED_VON_MISES_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_TSHELL
     * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
                   ipt = 0: middle
                   ipt = 1: inner
                   ipt = 2: outer
	 */
	D3P_TSHELL_MAX_PRINCIPAL_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_TSHELL
     * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
                   ipt = 0: middle
                   ipt = 1: inner
                   ipt = 2: outer
	 */
	D3P_TSHELL_2ND_PRINCIPAL_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_TSHELL
     * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
                   ipt = 0: middle
                   ipt = 1: inner
                   ipt = 2: outer
	 */
	D3P_TSHELL_MIN_PRINCIPAL_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_TSHELL
     * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
                   ipt = 0: middle
                   ipt = 1: inner
                   ipt = 2: outer
	 */
	D3P_TSHELL_TRESCA_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_TSHELL
	 * parameters: ist, ipt, ihv, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_TSHELL_HISTORY_VAR,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_TSHELL_MAXINT,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: iuser
	 */
	D3P_TSHELL_INTERNAL_ID,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_TSHELL_HISTORY_VAR_NUM,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_TSHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_TSHELL_ELEMENT_CENTROID,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_TSHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_TSHELL_INFINITESIMAL_STRAIN,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_TSHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_TSHELL_GREEN_STRAIN,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_TSHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_TSHELL_ALMANSI_STRAIN,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_TSHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_TSHELL_STRAIN_RATE,

	//BEAM
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NUM_BEAM,
    /**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_BEAM_PART,
	/**
	 * conversion: D3P_Beam
	 * length    : D3P_NUM_BEAM
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_BEAM_CONNECTIVITY_THIRD_MAT,
	/**
	 * conversion: int
	 * length    : D3P_NUM_BEAM
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_BEAM_IDS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_BEAM_AXIAL_FORCE,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_BEAM_S_SHEAR_RESULTANT,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_BEAM_T_SHEAR_RESULTANT,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_BEAM_S_BENDING_MOMENT,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_BEAM_T_BENDING_MOMENT,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_BEAM_TORSIONAL_RESULTANT,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_BEAM_AXIAL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_BEAM_RS_SHEAR_STRESS, 
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_BEAM_TR_SHEAR_STRESS, 
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_BEAM_AXIAL_PLASTIC_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_BEAM_AXIAL_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipt, ihv, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_BEAM_HISTORY_VAR,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_BEAM_MAXINT,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: iuser
	 */
	D3P_BEAM_INTERNAL_ID,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_BEAM_HISTORY_VAR_NUM,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_BEAM_ELEMENT_CENTROID,
	
	//SHELL
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NUM_SHELL,
    /**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_SHELL_PART,
	/**
	 * conversion: D3P_Shell
	 * length    : D3P_NUM_SHELL
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_CONNECTIVITY_MAT,
	/**
	 * conversion: int
	 * length    : D3P_NUM_SHELL
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_IDS,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_VON_MISES_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_SIGNED_VON_MISES_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_1ST_PRINCIPAL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_2ND_PRINCIPAL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_3RD_PRINCIPAL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_TRESCA_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_EFFECTIVE_PLASTIC_STRAIN,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
                   ipt = 0: middle
                   ipt = 1: inner
                   ipt = 2: outer
	 */
	D3P_SHELL_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
                   ipt = 0: middle
                   ipt = 1: inner
                   ipt = 2: outer
	 */
	D3P_SHELL_VON_MISES_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
                   ipt = 0: middle
                   ipt = 1: inner
                   ipt = 2: outer
	 */
	D3P_SHELL_SIGNED_VON_MISES_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
                   ipt = 0: middle
                   ipt = 1: inner
                   ipt = 2: outer
	 */
	D3P_SHELL_MAX_PRINCIPAL_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
                   ipt = 0: middle
                   ipt = 1: inner
                   ipt = 2: outer
	 */
	D3P_SHELL_2ND_PRINCIPAL_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
                   ipt = 0: middle
                   ipt = 1: inner
                   ipt = 2: outer
	 */
	D3P_SHELL_MIN_PRINCIPAL_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
                   ipt = 0: middle
                   ipt = 1: inner
                   ipt = 2: outer
	 */
	D3P_SHELL_TRESCA_STRAIN,
    /**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part, ipartset_user if by part set
                   ipt = 0: middle
                   ipt = 1: inner
                   ipt = 2: outer
	 */
    D3P_SHELL_PLASTIC_STRAIN,
    /**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
    D3P_SHELL_THERMAL_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_THICKNESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_ELEMENT_DEPENDENT_VAR_1,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_ELEMENT_DEPENDENT_VAR_2,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ihv, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_HISTORY_VAR,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_SHELL_MAXINT,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_MX,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_MY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_MXY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_QX,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_QY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_NX,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_NY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_NXY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_INTERNAL_ENERGY_DENSITY,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: iuser
	 */
	D3P_SHELL_INTERNAL_ID,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_SHELL_HISTORY_VAR_NUM,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_ELEMENT_CENTROID,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_INFINITESIMAL_STRAIN,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_GREEN_STRAIN,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_ALMANSI_STRAIN,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_STRAIN_RATE,

    //DELETION
    /**
     * conversion: bool
     * length    : 1
     * parameters: ist
     */
    D3P_HAS_DELETION,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID + D3P_NUM_TSHELL + D3P_NUM_SHELL + D3P_NUM_BEAM
	 * parameters: ist
	 */
	D3P_ALL_DELETION,
    /**
     * conversion: float
     * length    : D3P_NUM_SOLID
     * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
     */
    D3P_SOLID_DELETION,
    /**
     * conversion: float
     * length    : D3P_NUM_TSHELL
     * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
     */
    D3P_TSHELL_DELETION,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SHELL_DELETION,
    /**
     * conversion: float
     * length    : D3P_NUM_BEAM
     * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
     */
    D3P_BEAM_DELETION,

	//SPH
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_NUM_SPH,
    /**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
    D3P_NUM_SPH_PART,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_SPH_VARS,
	/**
	 * conversion: D3P_Sph
	 * length    : D3P_NUM_SPH
	 * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_NODE_MAT,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_RADIUS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_PRESSURE,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_PLASTIC_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_DENSITY, 
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_INTERNAL_ENERGY,
	/**
	 * conversion: int
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_NUMBER_OF_PARTICLE_NEIGHBORS,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_STRAIN,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_STRAIN_RATE,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_MASS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_VON_MISES_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_SIGNED_VON_MISES_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_VON_MISES_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_SIGNED_VON_MISES_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_1ST_PRINCIPAL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_2ND_PRINCIPAL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_3RD_PRINCIPAL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_TRESCA_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_MAX_PRINCIPAL_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_2ND_PRINCIPAL_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH
	 * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
	 */
	D3P_SPH_MIN_PRINCIPAL_STRAIN,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: iuser
	 */
	D3P_SPH_INTERNAL_ID,

	//DES
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_DES_DATA,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_DES_DATA,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ides if necessary
	 */
	D3P_NUM_DES_PART_IN_GEOM,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ides if necessary
	 */
	D3P_NUM_DES_ELEM_IN_GEOM,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ides if necessary
	 */
	D3P_NUM_DES_PART_IN_STATE,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ides if necessary
	 */
	D3P_NUM_DES_ELEM_IN_STATE,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ides if necessary
	 */
	D3P_NUM_DES_PART_VAR_IN_GEOM,
	/**
	 * conversion: D3P_VAR
	 * length    : D3P_NUM_DES_PART_VAR_IN_GEOM
	 * parameters: ides if necessary
	 */
	D3P_DES_PART_VAR_LIST_IN_GEOM,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ides if necessary
	 */
	D3P_NUM_DES_ELEM_VAR_IN_GEOM,
	/**
	 * conversion: D3P_VAR
	 * length    : D3P_NUM_DES_ELEM_VAR_IN_GEOM
	 * parameters: ides if necessary
	 */
	D3P_DES_ELEM_VAR_LIST_IN_GEOM,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ides if necessary
	 */
	D3P_NUM_DES_PART_VAR_IN_STATE,
	/**
	 * conversion: D3P_VAR
	 * length    : D3P_NUM_DES_PART_VAR_IN_STATE
	 * parameters: ides if necessary
	 */
	D3P_DES_PART_VAR_LIST_IN_STATE,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ides if necessary
	 */
	D3P_NUM_DES_ELEM_VAR_IN_STATE,
	/**
	 * conversion: D3P_VAR
	 * length    : D3P_NUM_DES_ELEM_VAR_IN_STATE
	 * parameters: ides if necessary
	 */
	D3P_DES_ELEM_VAR_LIST_IN_STATE,
	/**
	 * conversion: D3P_DES
	 * length    : D3P_NUM_DES_ELEM_IN_GEOM
	 * parameters: ides if necessary
	 */
	D3P_DES_NODAL_MAT_RADIUS_MASS_INERTIA,
	/**
	 * conversion: int/float..depends
	 * length    : D3P_NUM_DES_ELEM_IN_STATE
	 * parameters: var_name, ist, ides if necessary
	 */
	D3P_DES_DATA_IN_STATE,

	//CPM
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_CPM_DATA,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_CPM_NUM_AIRBAGS,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_CPM_NUM_PARTICLES,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_CPM_NUM_GEOM_VAR,
	/**
	 * conversion: D3P_VAR
	 * length    : D3P_CPM_NUM_GEOM_VAR
	 * parameters: ignore
	 */
	D3P_CPM_GEOM_VAR_LIST,
	/**
	 * conversion: int/float...depends
	 * length    : D3P_CPM_NUM_AIRBAGS
	 * parameters: var_name
	 */
	D3P_CPM_GEOM_DATA,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_CPM_NUM_STATE_VAR, 
	/**
	 * conversion: D3P_VAR
	 * length    : D3P_CPM_NUM_STATE_VAR
	 * parameters: ignore
	 */
	D3P_CPM_STATE_VAR_LIST,
	/**
	 * conversion: int/float...depends
	 * length    : D3P_CPM_NUM_PARTICLES
	 * parameters: var_name, ist
	 */
	D3P_CPM_STATE_DATA,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_CPM_NUM_STATE_GEOM_VAR,
	/**
	 * conversion: D3P_VAR
	 * length    : D3P_CPM_NUM_STATE_GEOM_VAR
	 * parameters: ignore
	 */
	D3P_CPM_STATE_GEOM_VAR_LIST,
	/**
	 * conversion: int/float...depends
	 * length    : D3P_CPM_NUM_AIRBAGS
	 * parameters: var_name, ist
	 */
	D3P_CPM_STATE_GEOM_DATA,

	// Rigid road surface
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_NODES_IN_RIGID_ROAD_SURFACE,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_SEGMENTS_IN_RIGID_ROAD_SURFACE,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_SURFACES_IN_RIGID_ROAD_SURFACE,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_MOTION_IN_RIGID_ROAD_SURFACE,
	/**
	 * conversion: int
	 * length    : D3P_NUM_NODES_IN_RIGID_ROAD_SURFACE
	 * parameters: ignore
	 */
	D3P_NODE_IDS_IN_RIGID_ROAD_SURFACE,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_NODES_IN_RIGID_ROAD_SURFACE
	 * parameters: ignore
	 */
	D3P_NODE_COORDINATES_IN_RIGID_ROAD_SURFACE,
	/**
	 * conversion: int
	 * length    : D3P_NUM_SURFACES_IN_RIGID_ROAD_SURFACE
	 * parameters: ignore
	 */
	D3P_SURFACE_IDS_IN_RIGID_ROAD_SURFACE,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: isurface
	 */
	D3P_NUM_SEGMENTS_OF_SURFACE_IN_RIGID_ROAD_SURFACE,
	/**
	 * conversion: D3P_SegmentOfRoadSurf
	 * length    : D3P_NUM_SEGMENTS_OF_SURFACE_IN_RIGID_ROAD_SURFACE
	 * parameters: isurface
	 */
	D3P_SEGMENT_CONNECTIVITY_OF_SURFACE_IN_RIGID_ROAD_SURFACE,
	/**
	 * conversion: float
	 * length    : D3P_MOTION_IN_RIGID_ROAD_SURFACE
	 * parameters: ignore
	 */
	D3P_RGSURF_STATE_DATA,

	// Rigid body motion
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_RIGID_BODY_IN_RIGID_BODY_MOTION,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: i_rigid_body
	 */
	D3P_NUM_NODES_IN_RIGID_BODY_MOTION,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_ACTIVE_NODE_IN_RIGID_BODY_MOTION,
	/**
	 * conversion: int
	 * length    : D3P_NUM_RIGID_BODY_IN_RIGID_BODY_MOTION
	 * parameters: ignore
	 */
	D3P_PART_INTERNAL_IDS_IN_RIGID_BODY_MOTION,
	/**
	 * conversion: int
	 * length    : D3P_NUM_NODES_IN_RIGID_BODY_MOTION
	 * parameters: i_rigid_body
	 */
	D3P_NODE_INTERNAL_IDS_IN_RIGID_BODY_MOTION,
	/**
	 * conversion: int
	 * length    : D3P_NUM_ACTIVE_NODE_IN_RIGID_BODY_MOTION
	 * parameters: ignore
	 */
	D3P_ACTIVE_NODE_INTERNAL_IDS_IN_RIGID_BODY_MOTION,
	/**
	 * conversion: D3P_RBodyMotion
	 * length    : D3P_NUM_RIGID_BODY_IN_RIGID_BODY_MOTION
	 * parameters: ist
	 */
	D3P_RIGID_BODY_STATE_DATA_IN_RIGID_BODY_MOTION,
	/**
	 * conversion: D3P_RBodyMotionDouble
	 * length    : D3P_NUM_RIGID_BODY_IN_RIGID_BODY_MOTION
	 * parameters: ist
	 */
	D3P_RIGID_BODY_STATE_DATA_DOUBLE_IN_RIGID_BODY_MOTION,

	//MS
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_MS_NUM_DOMAINS,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: index_multisolver
	 */
	 D3P_MS_DOMAIN_ID,
	/**
	 * conversion: char[]
	 * length    : 80
	 * parameters: index_multisolver
	 */
	D3P_MS_DOMAIN_NAME,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: index_multisolver
	 */
	D3P_MS_DOMAIN_IS_FOLLOW_SURFACE_METHOD,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: index_multisolver
	 */
	D3P_MS_DOMAIN_IS_SOLID,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: index_multisolver
	 */
	D3P_MS_DOMAIN_IS_SHELL,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: index_multisolver
	 */
	D3P_MS_DOMAIN_IS_BEAM,
	/**
	* conversion: int
	* length    : 1
	* parameters: index_multisolver
	*/
	D3P_MS_DOMAIN_IS_TSHELL,
	/**
	* conversion: int
	* length    : 1
	* parameters: index_multisolver
	*/
	D3P_MS_DOMAIN_NUM_PART,
	/**
	* conversion: int
	* length    : D3P_MS_DOMAIN_PART_NUM
	* parameters: index_multisolver
	*/
	D3P_MS_DOMAIN_PART_MAT,
	/**
	* conversion: int
	* length    : D3P_MS_DOMAIN_PART_NUM
	* parameters: index_multisolver
	*/
	D3P_MS_DOMAIN_PART_IDS,
	/**
     * conversion: bool
     * length    : 1
     * parameters: index_multisolver
     */
	D3P_MS_DOMAIN_IS_ADAPTIVE,
	/**
	* conversion: int
	* length    : 1
	* parameters: index_multisolver, ist if adaptive model
	*/
	D3P_MS_DOMAIN_NUM_NODE,
	/**
	* conversion: int
	* length    : D3P_MS_DOMAIN_NUM_NODE
	* parameters: index_multisolver, ist if adaptive model
	*/
	D3P_MS_DOMAIN_NODE_IDS,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: index_multisolver, ist if adaptive model
	 */
	D3P_MS_DOMAIN_NUM_NODE_ON_SURFACE,
	/**
	 * conversion: int
	 * length    : D3P_MS_DOMAIN_NUM_NODE_ON_SURFACE
	 * parameters: index_multisolver, ist if adaptive model
	 */
	D3P_MS_DOMAIN_NODE_IDS_ON_SURFACE,
    /**
     * conversion: D3P_Vector
     * length    : D3P_MS_DOMAIN_NUM_NODE
     * parameters: index_multisolver, ist if adaptive model
     */
    D3P_MS_DOMAIN_NODE_COORDINATES,
	/**
	* conversion: int
	* length    : 1
	* parameters: index_multisolver, ist if adaptive model
	*/
	D3P_MS_DOMAIN_NUM_ELEM,
	/**
	* conversion: int
	* length    : D3P_MS_DOMAIN_NUM_ELEM
	* parameters: index_multisolver, ist if adaptive model
	*/
	D3P_MS_DOMAIN_ELEM_IDS,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: index_multisolver
	 */
	D3P_MS_DOMAIN_DATA_IS_ON_STRUCTURE_ELEMENT,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: index_multisolver
	 */
	D3P_MS_DOMAIN_DATA_IS_ON_MS_NODE,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: index_multisolver
	 */
	D3P_MS_DOMAIN_DATA_IS_ON_MS_ELEMENT,
    /**
     * conversion: D3P_Solid
     * length    : D3P_MS_DOMAIN_NUM_ELEM
     * parameters: index_multisolver, ist if adaptive model
     */
    D3P_MS_SOLID_CONNECTIVITY_MAT,
    /**
     * conversion: D3P_Shell
     * length    : D3P_MS_DOMAIN_NUM_ELEM
     * parameters: index_multisolver, ist if adaptive model
     */
    D3P_MS_SHELL_CONNECTIVITY_MAT,
    /**
     * conversion: D3P_Beam
     * length    : D3P_MS_DOMAIN_NUM_ELEM
     * parameters: index_multisolver, ist if adaptive model
     */
    D3P_MS_BEAM_CONNECTIVITY_MAT,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: index_multisolver
	 */
	D3P_MS_DOMAIN_VAR_NUM,
	/**
	 * conversion: int
	 * length    : D3P_MS_DOMAIN_VAR_NUM
	 * parameters: index_multisolver
	 */
	 D3P_MS_DOMAIN_VARS_LIST,
	/**
	 * conversion: char
	 * length    : 80
	 * parameters: id_var_multisolver
	 */
	 D3P_MS_VAR_NAME,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: id_var_multisolver
	 */
	 D3P_MS_VAR_IS_VECTOR,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: id_var_multisolver
	 */
	 D3P_MS_VAR_IS_SCALAR,
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: id_var_multisolver
	 */
	 D3P_MS_VAR_IS_TENSOR,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: index_multisolver, ist if adaptive model
	 */
	D3P_MS_DOMAIN_VAR_LENGTH,
	/**
	 * conversion: float or D3P_Vector or D3P_Tensor
	 * length    : D3P_MS_DOMAIN_VAR_LENGTH
	 * parameters: index_multisolver, ist, id_var_multisolver
	 */
	D3P_MS_DOMAIN_DATA_IN_STATE,

	/**
	 * conversion: int
	 * length    : 1
	 * parameters: index_multisolver, ist
	 */
	D3P_MS_DOMAIN_NODE_NUM_ONSURFACE_IN_STATE,
	/**
	 * conversion: int
	 * length    : D3P_MS_DOMAIN_NODE_NUM_ONSURFACE_IN_STATE
	 * parameters: index_multisolver, ist
	 */
	D3P_MS_DOMAIN_SURFACE_IDS_IN_STATE,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: index_multisolver, ist
	 */
	D3P_MS_DOMAIN_ELEM_NUM_IN_STATE,
	/**
	if D3P_MS_DOMAIN_IS_SOLID && !D3P_MS_DOMAIN_DATA_IS_ON_STRUCTURE_ELEMENT
	 * conversion: D3P_Solid
	 * length    : D3P_MS_DOMAIN_ELEM_NUM_IN_STATE
	 * parameters: index_multisolver, ist
	 */
	D3P_MS_SOLID_CONNECTIVITY_MAT_IN_STATE,
	/**
	if D3P_MS_DOMAIN_IS_SHELL && !D3P_MS_DOMAIN_DATA_IS_ON_STRUCTURE_ELEMENT
	 * conversion: D3P_Shell
	 * length    : D3P_MS_DOMAIN_ELEM_NUM_IN_STATE
	 * parameters: index_multisolver, ist
	 */
	D3P_MS_SHELL_CONNECTIVITY_MAT_IN_STATE,
	/**
	if D3P_MS_DOMAIN_IS_BEAM && !D3P_MS_DOMAIN_DATA_IS_ON_STRUCTURE_ELEMENT
	 * conversion: D3P_Beam
	 * length    : D3P_MS_DOMAIN_ELEM_NUM_IN_STATE
	 * parameters: index_multisolver, ist
	 */
	D3P_MS_BEAM_CONNECTIVITY_MAT_IN_STATE,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: index_multisolver, ist
	 */
	D3P_MS_DOMAIN_NODE_NUM_IN_STATE,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_MS_DOMAIN_NODE_NUM_IN_STATE
	 * parameters: index_multisolver, ist
	 */
	D3P_MS_DOMAIN_COORD_IN_STATE,
	/**
	* conversion: int
	* length    : 1
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_ENERGY_VAR_NUM,
	/**
	* conversion: int
	* length    : D3P_MS_DOMAIN_ENERGY_VAR_NUM
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_ENERGY_VARS_LIST,
	/**
	if D3P_MS_DOMAIN_IS_SHELL && D3P_MS_DOMAIN_DATA_IS_ON_STRUCTURE_ELEMENT
	* conversion: D3P_Shell
	* length    : D3P_MS_DOMAIN_ELEM_NUM_IN_STATE
	* parameters: index_multisolver, ist
	*/
	//D3P_MS_SURFACE_SHELL_CONNECTIVITY_MAT_IN_STATE,
	/**
	if D3P_MS_DOMAIN_IS_BEAM && D3P_MS_DOMAIN_DATA_IS_ON_STRUCTURE_ELEMENT
	* conversion: D3P_Beam
	* length    : D3P_MS_DOMAIN_ELEM_NUM_IN_STATE
	* parameters: index_multisolver, ist
	*/
	//D3P_MS_SURFACE_BEAM_CONNECTIVITY_MAT_IN_STATE,
	/**
	* conversion: int
	* length    : 1
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_TETRAHEDRAL_NUM_IN_STATE,
	/**
	* conversion: int
	* length    : 1
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_PYRAMID_NUM_IN_STATE,
	/**
	* conversion: int
	* length    : 1
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_WEDGE_NUM_IN_STATE,
	/**
	* conversion: int
	* length    : 1
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_TRIA_NUM_IN_STATE,
	/**
	* conversion: int
	* length    : 1
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_QUAD_NUM_IN_STATE,
	/**
	* conversion: int
	* length    : 1
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_HEXA_NUM_IN_STATE,
	/**
	if D3P_MS_DOMAIN_TETRAHEDRAL_NUM_IN_STATE > 0
	* conversion: D3P_SOLIDTET
	* length    : D3P_MS_DOMAIN_ELEM_NUM_IN_STATE
	* parameters: index_multisolver, ist
	*/
	D3P_MS_ORIG_CONNECTIVITY_TETRA_IN_STATE,
	/**
	if D3P_MS_DOMAIN_ELEM_NUM_IN_STATE > 0 && this item exist
	* conversion: D3P_OLDSOLIDELE
	* length    : D3P_MS_DOMAIN_ELEM_NUM_IN_STATE
	* parameters: index_multisolver, ist
	*/
	D3P_MS_ORIG_CONNECTIVITY_MAT_IN_STATE,
	/**
	if D3P_MS_DOMAIN_ELEM_NUM_IN_STATE > 0 && this item exist
	* conversion: D3P_SEGMENT2
	* length    : D3P_MS_DOMAIN_ELEM_NUM_IN_STATE
	* parameters: index_multisolver, ist
	*/
	D3P_MS_ORIG_CONNECTIVITY_BEAM_IN_STATE,
	/**
	if D3P_MS_DOMAIN_ELEM_NUM_IN_STATE > 0 && this item exist
	* conversion: D3P_SOLIDFACE
	* length    : D3P_MS_DOMAIN_ELEM_NUM_IN_STATE
	* parameters: index_multisolver, ist
	*/
	D3P_MS_ORIG_CONNECTIVITY_FACE_IN_STATE,
	/**
	if D3P_MS_DOMAIN_PYRAMID_NUM_IN_STATE > 0
	* conversion: D3P_SOLIDFACE
	* length    : D3P_MS_DOMAIN_PYRAMID_NUM_IN_STATE
	* parameters: index_multisolver, ist
	*/
	D3P_MS_ORIG_CONNECTIVITY_PYRAM_IN_STATE,
	/**
	if D3P_MS_DOMAIN_WEDGE_NUM_IN_STATE > 0
	* conversion: D3P_SOLIDFACE
	* length    : D3P_MS_DOMAIN_WEDGE_NUM_IN_STATE
	* parameters: index_multisolver, ist
	*/
	D3P_MS_ORIG_CONNECTIVITY_WEDGE_IN_STATE,
	/**
	if D3P_MS_DOMAIN_HEXA_NUM_IN_STATE > 0
	* conversion: D3P_SOLIDFACE
	* length    : D3P_MS_DOMAIN_HEXA_NUM_IN_STATE
	* parameters: index_multisolver, ist
	*/
	D3P_MS_ORIG_CONNECTIVITY_HEXA_IN_STATE,
	/**
	* if this item exist
	* conversion: int
	* length    : 1
	* parameters: index_multisolver
	*/
	D3P_MS_DOMAIN_SOLVER_FLAG,
	/**
	* if this item exist
	* conversion: float
	* length    : D3P_MS_DOMAIN_VAR_LENGTH
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_PARTICLE_LIST,
	/**
	* if D3P_MS_DOMAIN_TRIA_NUM_IN_STATE > 0
	* conversion: D3P_TRIAELE
	* length    : D3P_MS_DOMAIN_ELEM_NUM_IN_STATE
	* parameters: index_multisolver, ist
	*/
	D3P_MS_ORIG_CONNECTIVITY_TRIA_IN_STATE,
	/**
	* if D3P_MS_DOMAIN_ELEM_NUM_IN_STATE > 0 && this item exist
	* conversion: D3P_SOLIDFACE
	* length    : D3P_MS_DOMAIN_ELEM_NUM_IN_STATE
	* parameters: index_multisolver, ist
	*/
	D3P_MS_ORIG_SHELL_CONNECTIVITY_IN_STATE,
	/**
	* if D3P_MS_DOMAIN_QUAD_NUM_IN_STATE > 0
	* conversion: D3P_SOLIDFACE
	* length    : D3P_MS_DOMAIN_QUAD_NUM_IN_STATE
	* parameters: index_multisolver, ist
	*/
	D3P_MS_QUAD_CONNECTIVITY_MAT_IN_STATE,
	/**
	* conversion: int
	* length    : 1
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_ENERGY_GROUPS_NUM,
	/**
	* conversion: int
	* length    : D3P_MS_DOMAIN_ENERGY_GROUPS_NUM
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_ENERGY_GROUP_NODES,
	/**
	* conversion: int
	* length    : 1
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_INTEGRATION_POINTS,
	/**
	* if this item exist
	* conversion: int
	* length    : 1
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_EDGES_NUM,
	/**
	* conversion: int
	* length    : 1
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_EDGE_DOMAIN_NUM,
	/**
	* if NUMBER_OF_EDGE_DOMAIN > 0
	* conversion: int
	* length    : NUMBER_OF_EDGE_DOMAIN
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_EDGES_PER_DOMAIN_NUMS,
	/**
	* if NUMBER_OF_EDGE_DOMAIN > 0
	* conversion: int
	* length    : D3P_MS_DOMAIN_EDGE_DOMAIN_NUM accumulate D3P_MS_DOMAIN_EDGES_PER_DOMAIN_NUMS
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_NODE_EDGE_CONNECTIVITY,
	/**
	* if NUMBER_OF_EDGE_DOMAIN > 0
	* conversion: int
	* length    : accumulate D3P_MS_DOMAIN_EDGES_PER_DOMAIN_NUMS
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_EDGE_DOMAIN_LIST,
	/**
	* conversion: int
	* length    : 1
	* parameters: index_multisolver
	*/
	D3P_MS_DOMAIN_PART_NUM,
	/**
	* conversion: int
	* length    : D3P_MS_DOMAIN_PART_NUM+D3P_MS_DOMAIN_PART_NUM
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_PART_LIST,
	/**
	* conversion: int
	* length    : D3P_MS_DOMAIN_VAR_LENGTH
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_NODE_LIST,
	/**
	* conversion: int
	* length    : D3P_MS_DOMAIN_NODE_NUM_IN_STATE
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_NODE_USER_ID,
	/**
	* conversion: int
	* length    : D3P_MS_DOMAIN_ELEM_NUM_IN_STATE
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_ELEM_USER_ID,
	/**
	* conversion: int
	* length    : 1
	* parameters: index_multisolver, ist
	*/
	D3P_MS_DOMAIN_SURFACE_NODE_NUM_IN_STATE,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	D3P_MS_NUM_PART_TITLE,

	// history data
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: ignore
	 */
	D3P_GLOBAL_KINETIC_ENERGY_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: ignore
	 */
	D3P_GLOBAL_INTERNAL_ENERGY_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: ignore
	 */
	D3P_GLOBAL_TOTAL_ENERGY_HISTORY,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_STATES
	 * parameters: ignore
	 */
	D3P_GLOBAL_VELOCITY_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt if necessary
                   shell node:
                   ipt = 0, middle
                   ipt = 1, inner
                   ipt = 2, outer
                   solid node: ignore ipt
	 */
	D3P_NODE_TEMPERATURE_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt if necessary
	 */
	D3P_SOLID_EFFECTIVE_PLASTIC_STRAIN_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt if necessary, ihv
	 */
	D3P_SOLID_HISTORY_VAR_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt
	 */
	D3P_TSHELL_EFFECTIVE_PLASTIC_STRAIN_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt, ihv
	 */
	D3P_TSHELL_HISTORY_VAR_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_BEAM_AXIAL_FORCE_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_BEAM_S_SHEAR_RESULTANT_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_BEAM_T_SHEAR_RESULTANT_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_BEAM_S_BENDING_MOMENT_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_BEAM_T_BENDING_MOMENT_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_BEAM_TORSIONAL_RESULTANT_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt
	 */
	D3P_BEAM_AXIAL_STRESS_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt
	 */
	D3P_BEAM_RS_SHEAR_STRESS_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt
	 */
	D3P_BEAM_TR_SHEAR_STRESS_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt
	 */
	D3P_BEAM_AXIAL_PLASTIC_STRAIN_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt
	 */
	D3P_BEAM_AXIAL_STRAIN_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt, ihv
	 */
	D3P_BEAM_HISTORY_VAR_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt
	 */
	D3P_SHELL_EFFECTIVE_PLASTIC_STRAIN_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SHELL_THICKNESS_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SHELL_ELEMENT_DEPENDENT_VAR_1_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SHELL_ELEMENT_DEPENDENT_VAR_2_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt, ihv
	 */
	D3P_SHELL_HISTORY_VAR_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SHELL_MX_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SHELL_MY_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SHELL_MXY_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SHELL_QX_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SHELL_QY_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SHELL_NX_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SHELL_NY_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SHELL_NXY_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SHELL_INTERNAL_ENERGY_DENSITY_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SOLID_DELETION_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_TSHELL_DELETION_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SHELL_DELETION_HISTORY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_BEAM_DELETION_HISTORY,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_NODE_HEAT_FLUX_HISTORY,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_NODE_COORDINATES_HISTORY,
    /**
	 * conversion: D3P_VectorDouble
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
    D3P_NODE_COORDINATES_DOUBLE_HISTORY,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_NODE_VELOCITIES_HISTORY,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_NODE_ACCELERATIONS_HISTORY,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SOLID_ELEMENT_CENTROID_HISTORY,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_TSHELL_ELEMENT_CENTROID_HISTORY,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_BEAM_ELEMENT_CENTROID_HISTORY,
	/**
	 * conversion: D3P_Vector
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SHELL_ELEMENT_CENTROID_HISTORY,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt if necessary
	 */
	D3P_SOLID_STRESS_HISTORY,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt if necessary
	 */
	D3P_SOLID_STRAIN_HISTORY,
    /**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
    D3P_SOLID_PLASTIC_STRAIN_HISTORY,
    /**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
    D3P_SOLID_THERMAL_STRAIN_HISTORY,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt
	 */
	D3P_TSHELL_STRESS_HISTORY,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt
                   ipt = 0, middle
                   ipt = 1, inner
                   ipt = 2, outer
	 */
	D3P_TSHELL_STRAIN_HISTORY,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt
	 */
	D3P_SHELL_STRESS_HISTORY,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt
                   ipt = 0, middle
                   ipt = 1, inner
                   ipt = 2, outer
	 */
	D3P_SHELL_STRAIN_HISTORY,
    /**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_STATES
	 * parameters: iuser, ipt
                   ipt = 0, middle
                   ipt = 1, inner
                   ipt = 2, outer
	 */
    D3P_SHELL_PLASTIC_STRAIN_HISTORY,
    /**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
    D3P_SHELL_THERMAL_STRAIN_HISTORY,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SPH_STRESS_HISTORY,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SPH_STRAIN_HISTORY,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_STATES
	 * parameters: iuser
	 */
	D3P_SPH_STRAIN_RATE_HISTORY,

	// New types only for Python
	/**
	 * conversion: ndarray
	 * length    : (D3P_NUM_NODES, 4)
	 * parameters: ist
	 */
	D3P_NODE_ID_COORDINATES,
	/**
	 * conversion: ndarray
	 * length    : (D3P_NUM_SHELL, 6)
	 * parameters: ignore, ist if adaptive model
	 */
	D3P_SHELL_ID_CONNECTIVITY_MAT,
	/**
	 * conversion: ndarray
	 * length    : (D3P_NUM_SOLID, 10)
	 * parameters: ignore, ist if adaptive model
	 */
	D3P_SOLID_ID_CONNECTIVITY_MAT,
	/**
	 * conversion: ndarray
	 * length    : (D3P_NUM_TSHELL, 10)
	 * parameters: ignore, ist if adaptive model
	 */
	D3P_TSHELL_ID_CONNECTIVITY_MAT,
	/**
	 * conversion: ndarray
	 * length    : (D3P_NUM_BEAM, 4)
	 * parameters: ignore, ist if adaptive model
	 */
	D3P_BEAM_ID_CONNECTIVITY_MAT,

	/*==================== D3plot end ====================*/



	/*==================== Interface force begin ====================*/
	// global
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	INF_NUM_STATES,
	/**
	 * conversion: float
	 * length    : INF_NUM_STATES
	 * parameters: ignore
	 */
	INF_TIMES,

	//nodes
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore, ist if adaptive model
	 */
	INF_NUM_NODES,
	/**
	 * conversion: D3P_Vector
	 * length    : INF_NUM_NODES
	 * parameters: ignore, ist if adaptive model
	 */
	INF_NODE_INITIAL_COORDINATES,
	/**
	 * conversion: int
	 * length    : INF_NUM_NODES
	 * parameters: ignore, ist if adaptive model
	 */
	INF_NODE_IDS,
	/**
     * conversion: D3P_Vector
     * length    : INF_NUM_NODES
     * parameters: ist
     */
	INF_NODE_COORDINATES,
	/**
     * conversion: D3P_Vector
     * length    : INF_NUM_NODES
     * parameters: ist
     */
	INF_NODE_VELOCITIES,
	/**
     * conversion: D3P_Vector
     * length    : INF_NUM_NODES
     * parameters: ist
     */
    INF_NODE_ACCELERATIONS,
	/**
     * conversion: D3P_VectorDouble
     * length    : INF_NUM_NODES
     * parameters: ist
     */
    INF_NODE_COORDINATES_DOUBLE,
    /**
     * conversion: D3P_VectorDouble
     * length    : INF_NUM_NODES
     * parameters: ist
     */
    INF_NODE_VELOCITIES_DOUBLE,
    /**
     * conversion: D3P_VectorDouble
     * length    : INF_NUM_NODES
     * parameters: ist
     */
    INF_NODE_ACCELERATIONS_DOUBLE,

	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore, ist if adaptive model
	 */
	INF_NUM_SEGMENTS,
	/**
     * conversion: D3P_Shell
     * length    : INF_NUM_SEGMENTS
     * parameters: ignore, ist if adaptive model
     */
    INF_SEGMENT_CONNECTIVITY_MAT,
	/**
	 * conversion: int
	 * length    : INF_NUM_SEGMENTS
	 * parameters: ignore, ist if adaptive model
	 */
	INF_SEGMENT_IDS,
	/**
	 * conversion: float
	 * length    : INF_NUM_SEGMENTS
	 * parameters: ist
	 */
	INF_INTERFACE_PRESSURE,
	/**
	 * conversion: float
	 * length    : INF_NUM_SEGMENTS
	 * parameters: ist
	 */
	INF_INTERFACE_SHEAR_STRESS,
	/**
	 * conversion: float
	 * length    : INF_NUM_SEGMENTS
	 * parameters: ist
	 */
	INF_R_INTERFACE_SHEAR_STRESS,
	/**
	 * conversion: float
	 * length    : INF_NUM_SEGMENTS
	 * parameters: ist
	 */
	INF_S_INTERFACE_SHEAR_STRESS,
	/**
	 * conversion: D3P_Vector
	 * length    : INF_NUM_SEGMENTS
	 * parameters: ist
	 */
	INF_N1_INTERFACE_FORCE,
	/**
	 * conversion: D3P_Vector
	 * length    : INF_NUM_SEGMENTS
	 * parameters: ist
	 */
	INF_N2_INTERFACE_FORCE,
	/**
	 * conversion: D3P_Vector
	 * length    : INF_NUM_SEGMENTS
	 * parameters: ist
	 */
	INF_N3_INTERFACE_FORCE,
	/**
	 * conversion: D3P_Vector
	 * length    : INF_NUM_SEGMENTS
	 * parameters: ist
	 */
	INF_N4_INTERFACE_FORCE,
	/**
	 * conversion: float
	 * length    : INF_NUM_SEGMENTS
	 * parameters: ist
	 */
	INF_N1_CONTACT_GAP,
	/**
	 * conversion: float
	 * length    : INF_NUM_SEGMENTS
	 * parameters: ist
	 */
	INF_N2_CONTACT_GAP,
	/**
	 * conversion: float
	 * length    : INF_NUM_SEGMENTS
	 * parameters: ist
	 */
	INF_N3_CONTACT_GAP,
	/**
	 * conversion: float
	 * length    : INF_NUM_SEGMENTS
	 * parameters: ist
	 */
	INF_N4_CONTACT_GAP,
	/**
	 * conversion: float
	 * length    : INF_NUM_SEGMENTS
	 * parameters: ist
	 */
	INF_SURFACE_ENERGY_DENSITY,
	/**
	 * conversion: __int64 or long long
	 * length    : 1
	 * parameters: ist
	 */
	INF_NUM_SEGMENT_STATE_DATA,
	/**
	 * conversion: float
	 * length    : INF_NUM_SEGMENT_STATE_DATA
	 * parameters: ist
	 */
	INF_SEGMENT_STATE_DATA,
	/*==================== Interface force end ====================*/

	/*==================== FSI force begin ====================*/
	// global
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	FSIFOR_NUM_STATES,
	/**
	 * conversion: float
	 * length    : FSIFOR_NUM_STATES
	 * parameters: ignore
	 */
	FSIFOR_TIMES,

	//nodes
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore, ist if adaptive model
	 */
	FSIFOR_NUM_NODES,
	/**
	 * conversion: D3P_Vector
	 * length    : FSIFOR_NUM_NODES
	 * parameters: ignore, ist if adaptive model
	 */
	FSIFOR_NODE_INITIAL_COORDINATES,
	/**
	 * conversion: int
	 * length    : FSIFOR_NUM_NODES
	 * parameters: ignore, ist if adaptive model
	 */
	FSIFOR_NODE_IDS,
	/**
     * conversion: D3P_Vector
     * length    : FSIFOR_NUM_NODES
     * parameters: ist
     */
	FSIFOR_NODE_COORDINATES,
	/**
     * conversion: D3P_Vector
     * length    : FSIFOR_NUM_NODES
     * parameters: ist
     */
	FSIFOR_NODE_VELOCITIES,
	/**
     * conversion: D3P_Vector
     * length    : FSIFOR_NUM_NODES
     * parameters: ist
     */
    FSIFOR_NODE_ACCELERATIONS,
	/**
     * conversion: D3P_VectorDouble
     * length    : FSIFOR_NUM_NODES
     * parameters: ist
     */
    FSIFOR_NODE_COORDINATES_DOUBLE,
    /**
     * conversion: D3P_VectorDouble
     * length    : FSIFOR_NUM_NODES
     * parameters: ist
     */
    FSIFOR_NODE_VELOCITIES_DOUBLE,
    /**
     * conversion: D3P_VectorDouble
     * length    : FSIFOR_NUM_NODES
     * parameters: ist
     */
    FSIFOR_NODE_ACCELERATIONS_DOUBLE,

	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore, ist if adaptive model
	 */
	FSIFOR_NUM_SEGMENTS,
	/**
     * conversion: D3P_Shell
     * length    : FSIFOR_NUM_SEGMENTS
     * parameters: ignore, ist if adaptive model
     */
    FSIFOR_SEGMENT_CONNECTIVITY_MAT,
	/**
	 * conversion: int
	 * length    : FSIFOR_NUM_SEGMENTS
	 * parameters: ignore, ist if adaptive model
	 */
	FSIFOR_SEGMENT_IDS,
	/**
	 * conversion: float
	 * length    : FSIFOR_NUM_SEGMENTS
	 * parameters: ist
	 */
	FSIFOR_NORMAL_INTERFACE_PRESSURE,
	/**
	 * conversion: float
	 * length    : FSIFOR_NUM_SEGMENTS
	 * parameters: ist
	 */
	FSIFOR_X_FORCE,
	/**
	 * conversion: float
	 * length    : FSIFOR_NUM_SEGMENTS
	 * parameters: ist
	 */
	FSIFOR_Y_FORCE,
	/**
	 * conversion: float
	 * length    : FSIFOR_NUM_SEGMENTS
	 * parameters: ist
	 */
	FSIFOR_Z_FORCE,
	/**
	 * conversion: float
	 * length    : FSIFOR_NUM_SEGMENTS
	 * parameters: ist
	 */
	FSIFOR_RELATIVE_INTERFACE_VELOCITY,
	/**
	 * conversion: float
	 * length    : FSIFOR_NUM_SEGMENTS
	 * parameters: ist
	 */
	FSIFOR_X_INTERFACE_VELOCITY,
	/**
	 * conversion: float
	 * length    : FSIFOR_NUM_SEGMENTS
	 * parameters: ist
	 */
	FSIFOR_Y_INTERFACE_VELOCITY,
	/**
	 * conversion: float
	 * length    : FSIFOR_NUM_SEGMENTS
	 * parameters: ist
	 */
	FSIFOR_Z_INTERFACE_VELOCITY,
	/*==================== FSI force end ====================*/



	/*==================== NVH begin ====================*/
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_FREQUENCY,
	/**
	 * conversion: float
	 * length    : D3P_NUM_FREQUENCY
	 * parameters: ignore
	 */
	D3P_FREQUENCIES,

	// NODAL DATA (D3SSD, D3SPCM, D3PSD, D3RMS, D3ZCF)
	/**
	* conversion: D3P_Vector
	* length    : D3P_NUM_NODES
	* parameters: ist, option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	*/
	D3P_FREQUENCY_NODE_DISPLACEMENTS,
	/**
	* conversion: D3P_Vector
	* length    : D3P_NUM_NODES
	* parameters: ist, option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	*/
	D3P_FREQUENCY_NODE_VELOCITIES,
	/**
	* conversion: D3P_Vector
	* length    : D3P_NUM_NODES
	* parameters: ist, option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	*/
	D3P_FREQUENCY_NODE_ACCELERATIONS,
	/**
	 * conversion: D3P_VectorDouble
	 * length    : D3P_NUM_NODES
	 * parameters: ist, option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_NODE_DISPLACEMENTS_DOUBLE,
	/**
	 * conversion: D3P_VectorDouble
	 * length    : D3P_NUM_NODES
	 * parameters: ist, option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_NODE_VELOCITIES_DOUBLE,
	/**
	 * conversion: D3P_VectorDouble
	 * length    : D3P_NUM_NODES
	 * parameters: ist, option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_NODE_ACCELERATIONS_DOUBLE,

	// ELEMENT DATA (D3SSD, D3SPCM, D3PSD, D3RMS, D3ZCF)
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipt if necessary, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_SOLID_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipt if necessary, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_SOLID_VON_MISES_STRESS,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipt if necessary, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_SOLID_STRAIN,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_TSHELL
	 * parameters: ist, ipt if necessary, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_TSHELL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_TSHELL
	 * parameters: ist, ipt if necessary, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_TSHELL_VON_MISES_STRESS,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_TSHELL
     * parameters: ist, ipt, ipart or ipart_user if by part
                   ipt = 0: mean
                   ipt = 1: inner
                   ipt = 2: outer
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_TSHELL_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_BEAM_AXIAL_FORCE,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_BEAM_S_SHEAR_RESULTANT,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_BEAM_T_SHEAR_RESULTANT,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_BEAM_S_BENDING_MOMENT,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_BEAM_T_BENDING_MOMENT,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_BEAM_TORSIONAL_RESULTANT,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipt, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_BEAM_AXIAL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipt, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_BEAM_RS_SHEAR_STRESS, 
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipt, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_BEAM_TR_SHEAR_STRESS, 
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipt, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_BEAM_AXIAL_PLASTIC_STRAIN,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipt, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_BEAM_AXIAL_STRAIN,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_SHELL_STRESS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt if necessary, ipart or ipart_user if by part
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_SHELL_VON_MISES_STRESS,
	/**
	 * conversion: D3P_Tensor
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part
                   ipt = 0: mean
                   ipt = 1: inner
                   ipt = 2: outer
				   option(for complex version d3ssd: 1-amplitude, 2-phase angle)
	 */
	D3P_FREQUENCY_SHELL_STRAIN,

	// D3FTG
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID
	 * parameters: ist, ipt, ipart or ipart_user if by part
	 */
	D3P_FTG_SOLID_CUMULATIVE_DAMAGE_RATIO,
	D3P_FTG_SOLID_EXPECTED_FATIGUE_LIFE,
	D3P_FTG_SOLID_ZERO_CROSSING_FREQUENCY,
	D3P_FTG_SOLID_PEAK_CROSSING_FREQUENCIES,
	D3P_FTG_SOLID_IRREGULARITY_FACTORS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_TSHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part
	 */
	D3P_FTG_TSHELL_CUMULATIVE_DAMAGE_RATIO,
	D3P_FTG_TSHELL_EXPECTED_FATIGUE_LIFE,
	D3P_FTG_TSHELL_ZERO_CROSSING_FREQUENCY,
	D3P_FTG_TSHELL_PEAK_CROSSING_FREQUENCIES,
	D3P_FTG_TSHELL_IRREGULARITY_FACTORS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM
	 * parameters: ist, ipt, ipart or ipart_user if by part
	 */
	D3P_FTG_BEAM_CUMULATIVE_DAMAGE_RATIO,
	D3P_FTG_BEAM_EXPECTED_FATIGUE_LIFE,
	D3P_FTG_BEAM_ZERO_CROSSING_FREQUENCY,
	D3P_FTG_BEAM_PEAK_CROSSING_FREQUENCIES,
	D3P_FTG_BEAM_IRREGULARITY_FACTORS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL
	 * parameters: ist, ipt, ipart or ipart_user if by part
	 */
	D3P_FTG_SHELL_CUMULATIVE_DAMAGE_RATIO,
	D3P_FTG_SHELL_EXPECTED_FATIGUE_LIFE,
	D3P_FTG_SHELL_ZERO_CROSSING_FREQUENCY,
	D3P_FTG_SHELL_PEAK_CROSSING_FREQUENCIES,
	D3P_FTG_SHELL_IRREGULARITY_FACTORS,

	// D3ACS
	/**
	 * conversion: float
	 * length    : D3P_NUM_NODES
	 * parameters: ignore
	 */
	D3P_ACS_ACOUSTIC_PRESSURE_REAL,
	D3P_ACS_ACOUSTIC_PRESSURE_IMAGINARY,
	D3P_ACS_ACOUSTIC_INTENSITY,
	D3P_ACS_SOUND_PRESSURE_LEVEL_dB,
	D3P_ACS_NORMAL_VELOCITY_REAL,
	D3P_ACS_NORMAL_VELOCITY_IMAGINARY,

	// D3ATV
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_ATV_NUM_FIELD_POINT,
	/**
	 * conversion: int
	 * length    : D3P_ATV_NUM_FIELD_POINT
	 * parameters: ignore
	 */
	D3P_ATV_FIELD_POINTS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_NODES
	 * parameters: ist, ifieldpoint
	 */
	D3P_ATV_ACOUSTIC_PRESSURE_REAL,
	D3P_ATV_ACOUSTIC_PRESSURE_IMAGINARY,
	D3P_ATV_SOUND_PRESSURE_LEVEL_dB,

	// D3EIGV
	/**
     * conversion: int
     * length    : 1
     * parameters: ignore, ist if adaptive model, ipart or ipart_user if by part, ipartset_user if by part set
     */
	D3P_EIGV_NUM_NODES,
	/**
     * conversion: D3P_Vector
     * length    : D3P_EIGV_NUM_NODES
     * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
     */
	D3P_EIGV_NODE_COORDINATES,
    /**
     * conversion: D3P_Vector
     * length    : D3P_EIGV_NUM_NODES
     * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
     */
	D3P_EIGV_NODE_VELOCITIES,
    /**
     * conversion: D3P_Vector
     * length    : D3P_EIGV_NUM_NODES
     * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
     */
    D3P_EIGV_NODE_ACCELERATIONS,
	/**
     * conversion: D3P_VectorDouble
     * length    : D3P_EIGV_NUM_NODES
     * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
     */
	D3P_EIGV_NODE_COORDINATES_DOUBLE,
    /**
     * conversion: D3P_VectorDouble
     * length    : D3P_EIGV_NUM_NODES
     * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
     */
	D3P_EIGV_NODE_VELOCITIES_DOUBLE,
    /**
     * conversion: D3P_VectorDouble
     * length    : D3P_EIGV_NUM_NODES
     * parameters: ist, ipart or ipart_user if by part, ipartset_user if by part set
     */
    D3P_EIGV_NODE_ACCELERATIONS_DOUBLE,


	// D3EIGV_AC
	/**
	 * conversion: float
	 * length    : D3P_NUM_NODES
	 * parameters: ist
	 */
	D3P_EIGV_AC_ACOUSTIC_PRESSURE_REAL,

	// D3ERP
	/**
	 * conversion: float
	 * length    : D3P_NUM_NODES
	 * parameters: ist
	 */
	D3P_ERP_NORMAL_VELOCITY_REAL,
	D3P_ERP_NORMAL_VELOCITY_IMAGINARY,
	D3P_ERP_NORMAL_VELOCITY_ABSOLUTE,
	D3P_ERP_ACOUSTIC_INTENSITY,
	D3P_ERP_ACOUSTIC_ERP_DENSITY,

	// D3ACP
	/**
	 * conversion: float
	 * length    : D3P_NUM_NODES
	 * parameters: ist
	 */
	D3P_ACP_ACOUSTIC_PRESSURE_REAL,
	D3P_ACP_ACOUSTIC_PRESSURE_IMAGINARY,
	D3P_ACP_ACOUSTIC_INTENSITY,
	D3P_ACP_SOUND_PRESSURE_LEVEL_dB,

	// D3ACC
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_ACC_NUM_FIELD_POINT,
	/**
	 * conversion: int
	 * length    : D3P_ACC_NUM_FIELD_POINT
	 * parameters: ignore
	 */
	D3P_ACC_FIELD_POINTS,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL(only support shell elements)
	 * parameters: ist, ifieldpoint, ipart or ipart_user if by part
	 */
	D3P_ACC_SHELL_ACOUSTIC_PRESSURE_CONTRIBUTION_REAL,
	D3P_ACC_SHELL_ACOUSTIC_PRESSURE_CONTRIBUTION_IMAGINARY,
	D3P_ACC_SHELL_ACOUSTIC_PRESSURE_CONTRIBUTION_PERCENTAGE,

	/*====================  NVH end  ====================*/

	/*====================  ALE begin ===================*/
	/*
	* conversion : int
	* length     : 1
	* parameters : ignore
	*/
	D3P_ALE_NUM_FLUID_GROUP,
	/*
	* conversion : int
	* length     : 1
	* parameters : ignore
	*/
	D3P_ALE_NUM_FLUID_PART,
	/*
	* conversion : int
	* length     : D3P_ALE_NUM_FLUID_PART
	* parameters : ignore
	*/
	D3P_ALE_MATERIAL_IDS,
	/*
	* conversion : float
	* length     : D3P_NUM_SOLID
	* parameters : ist
	*/
	D3P_ALE_DENSITY,
	/*
	* conversion : float
	* length     : D3P_NUM_SOLID
	* parameters : ist, id_fluid_group (from 1 to D3P_ALE_NUM_FLUID_GROUP)
	*/
	D3P_ALE_VOLUME_FRACTION,
	/*
	* conversion : float
	* length     : D3P_NUM_SOLID
	* parameters : ist
	*/
	D3P_ALE_DOMINANT_MATERIAL,
	/*
	* conversion : float
	* length     : D3P_NUM_SOLID
	* parameters : ist, id_fluid_group (from 1 to D3P_ALE_NUM_FLUID_GROUP)
	*/
	D3P_ALE_SPECIES_MASS,
	/*
	* conversion : float
	* length     : D3P_NUM_SHELL
	* parameters : ist
	*/
	D3P_2D_ALE_DENSITY,
	/*
	* conversion : float
	* length     : D3P_NUM_SHELL
	* parameters : ist, id_fluid_group (from 1 to D3P_ALE_NUM_FLUID_GROUP)
	*/
	D3P_2D_ALE_VOLUME_FRACTION,
	/*
	* conversion : float
	* length     : D3P_NUM_SHELL
	* parameters : ist
	*/
	D3P_2D_ALE_DOMINANT_MATERIAL,
	/*
	* conversion : float
	* length     : D3P_NUM_SHELL
	* parameters : ist, id_fluid_group (from 1 to D3P_ALE_NUM_FLUID_GROUP)
	*/
	D3P_2D_ALE_SPECIES_MASS,
	/*====================  ALE end  ====================*/
	



	/*====================  d3thdt start  ====================*/
	/*
	* conversion : int
	* length     : 1
	* parameters : ignore
	*/
	D3T_NUM_STATES,
	/**
	 * conversion: float
	 * length    : D3T_NUM_STATES
	 * parameters: ignore
	 */
	D3T_TIMES,
    /**
     * conversion: float
     * length    : 1
     * parameters: ist
     */
    D3T_GLOBAL_KINETIC_ENERGY,
    /**
     * conversion: float
     * length    : 1
     * parameters: ist
     */
    D3T_GLOBAL_INTERNAL_ENERGY,
    /**
     * conversion: float
     * length    : 1
     * parameters: ist
     */
    D3T_GLOBAL_TOTAL_ENERGY,
    /**
     * conversion: D3P_Vector
     * length    : 1
     * parameters: ist
     */
    D3T_GLOBAL_VELOCITY,
    /**
     * conversion: int
     * length    : 1
     * parameters: ignore
     */
    D3T_NUM_PARTS,
    /**
     * conversion: int
     * length    : D3T_NUM_PARTS
     * parameters: ignore
     */
    D3T_PART_IDS,
    /**
     * conversion: int
     * length    : 1
     * parameters: ignore
     */
    D3T_NUM_PART_NAME,
    /**
     * conversion: char
     * length    : 80
     * parameters: ipart_user or ipart
     */
    D3T_PART_NAME,
    /**
     * conversion: D3P_PartTitle
     * length    : D3T_NUM_PART_NAME
     * parameters: ignore
     */
    D3T_PART_NAME_STRUCT,
    /**
     * conversion: float
     * length    : 1
     * parameters: ist, ipart_user or ipart
     */
    D3T_PART_INTERNAL_ENERGY,
    /**
     * conversion: float
     * length    : 1
     * parameters: ist, ipart_user or ipart
     */
    D3T_PART_KINETIC_ENERGY,
    /**
     * conversion: D3P_Vector
     * length    : 1
     * parameters: ist, ipart_user or ipart
     */
    D3T_PART_VELOCITY,
    /**
     * conversion: float
     * length    : 1
     * parameters: ist, ipart_user or ipart
     */
    D3T_PART_MASS,
    /**
     * conversion: float
     * length    : 1
     * parameters: ist, ipart_user or ipart
     */
    D3T_PART_HOURGLASS,
    /**
     * conversion: int
     * length    : 1
     * parameters: iuser
     */
    D3T_PART_INTERNAL_ID,

	/**
     * conversion: int
     * length    : 1
     * parameters: ignore
     */
    D3T_NUM_NODES,
    /**
     * conversion: int
     * length    : D3T_NUM_NODES
     * parameters: ignore
     */
    D3T_NODE_IDS,
    /**
     * conversion: D3P_Vector
     * length    : D3T_NUM_NODES
     * parameters: ignore
     */
    D3T_NODE_INITIAL_COORDINATES,
	/**
     * conversion: int
     * length    : 1
     * parameters: ignore
     */
    D3T_NUM_NODES_PLOT,
    /**
     * conversion: int
     * length    : D3T_NUM_NODES_PLOT
     * parameters: ignore
     */
    D3T_NODE_IDS_PLOT,
    /**
     * conversion: float
     * length    : D3T_NUM_STATES
     * parameters: iuser
     */
    D3T_NODE_TEMPERATURE_HISTORY,
	/**
     * conversion: D3P_Vector
     * length    : D3T_NUM_STATES
     * parameters: iuser
     */
    D3T_NODE_COORDINATES_HISTORY,
    /**
     * conversion: D3P_Vector
     * length    : D3T_NUM_STATES
     * parameters: iuser
     */
    D3T_NODE_VELOCITIES_HISTORY,
    /**
     * conversion: D3P_Vector
     * length    : D3T_NUM_STATES
     * parameters: iuser
     */
    D3T_NODE_ACCELERATIONS_HISTORY,

    /**
     * conversion: int
     * length    : 1
     * parameters: ignore
     */
	D3T_NUM_SOLID,
	/*
	* conversion : D3P_Solid
	* length     : D3T_NUM_SOLID
	* parameters : ignore
	*/
	D3T_SOLID_CONNECTIVITY_MAT,
	/*
	* conversion : int
	* length     : D3T_NUM_SOLID
	* parameters : ignore
	*/
	D3T_SOLID_IDS,
	/*
	* conversion : int
	* length     : 1
	* parameters : ignore
	*/
	D3T_NUM_SOLID_PLOT,
	/*
	* conversion : int
	* length     : D3T_NUM_SOLID_PLOT
	* parameters : ignore
	*/
	D3T_SOLID_IDS_PLOT,
    /**
     * conversion: D3P_Tensor
     * length    : D3T_NUM_STATES
     * parameters: iuser, ipt if necessary
     */
    D3T_SOLID_STRESS_HISTORY,
    /**
     * conversion: float
     * length    : D3T_NUM_STATES
     * parameters: iuser, ipt if necessary
     */
    D3T_SOLID_VON_MISES_STRESS_HISTORY,
    /**
     * conversion: float
     * length    : D3T_NUM_STATES
     * parameters: iuser, ipt if necessary
     */
    D3T_SOLID_EFFECTIVE_PLASTIC_STRAIN_HISTORY,
    /**
     * conversion: D3P_Tensor
     * length    : D3T_NUM_STATES
     * parameters: iuser
     */
    D3T_SOLID_STRAIN_HISTORY,


	/*
	* conversion : int
	* length     : 1
	* parameters : ignore
	*/
	D3T_NUM_SHELL,
	/*
	* conversion : D3P_Shell
	* length     : D3T_NUM_SHELL
	* parameters : ignore
	*/
	D3T_SHELL_CONNECTIVITY_MAT,
	/*
	* conversion : int
	* length     : D3T_NUM_SHELL
	* parameters : ignore
	*/
	D3T_SHELL_IDS,
	/*
	* conversion : int
	* length     : 1
	* parameters : ignore
	*/
	D3T_NUM_SHELL_PLOT,
	/*
	* conversion : int
	* length     : D3T_NUM_SHELL_PLOT
	* parameters : ignore
	*/
	D3T_SHELL_IDS_PLOT,
    /**
     * conversion: D3P_Tensor
     * length    : D3T_NUM_STATES
     * parameters: iuser, ipt
     */
    D3T_SHELL_STRESS_HISTORY,
    /**
     * conversion: float
     * length    : D3T_NUM_STATES
     * parameters: iuser, ipt
     */
    D3T_SHELL_VON_MISES_STRESS_HISTORY,
    /**
     * conversion: float
     * length    : D3T_NUM_STATES
     * parameters: iuser, ipt
     */
    D3T_SHELL_EFFECTIVE_PLASTIC_STRAIN_HISTORY,
    /**
     * conversion: D3P_Tensor
     * length    : D3T_NUM_STATES
     * parameters: iuser, ipt
     */
    D3T_SHELL_STRAIN_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser
	*/
	D3T_SHELL_MX_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser
	*/
	D3T_SHELL_MY_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser
	*/
	D3T_SHELL_MXY_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser
	*/
	D3T_SHELL_QX_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser
	*/
	D3T_SHELL_QY_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser
	*/
	D3T_SHELL_NX_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser
	*/
	D3T_SHELL_NY_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser
	*/
	D3T_SHELL_NXY_HISTORY,

	/*
	* conversion : int
	* length     : 1
	* parameters : ignore
	*/
	D3T_NUM_BEAM,
	/*
	* conversion : D3P_Beam
	* length     : D3T_NUM_BEAM
	* parameters : ignore
	*/
	D3T_BEAM_CONNECTIVITY_THIRD_MAT,
	/*
	* conversion : int
	* length     : D3T_NUM_BEAM
	* parameters : ignore
	*/
	D3T_BEAM_IDS,
	/*
	* conversion : int
	* length     : 1
	* parameters : ignore
	*/
	D3T_NUM_BEAM_PLOT,
	/*
	* conversion : int
	* length     : D3T_NUM_BEAM_PLOT
	* parameters : ignore
	*/
	D3T_BEAM_IDS_PLOT,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser
	*/
	D3T_BEAM_AXIAL_FORCE_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser
	*/
	D3T_BEAM_S_SHEAR_RESULTANT_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser
	*/
	D3T_BEAM_T_SHEAR_RESULTANT_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser
	*/
	D3T_BEAM_S_BENDING_MOMENT_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser
	*/
	D3T_BEAM_T_BENDING_MOMENT_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser
	*/
	D3T_BEAM_TORSIONAL_RESULTANT_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser, ipt
	*/
	D3T_BEAM_AXIAL_STRESS_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser, ipt
	*/
	D3T_BEAM_RS_SHEAR_STRESS_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser, ipt
	*/
	D3T_BEAM_TR_SHEAR_STRESS_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser, ipt
	*/
	D3T_BEAM_AXIAL_PLASTIC_STRAIN_HISTORY,
	/*
	* conversion : float
	* length     : D3T_NUM_STATES
	* parameters : iuser, ipt
	*/
	D3T_BEAM_AXIAL_STRAIN_HISTORY,
	/*====================  d3thdt end  ====================*/



	/*====================  raw data block api  ====================*/
	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_HAS_PROPERTY,
	/**
	 * conversion: D3P_Control
	 * length    : 1
	 * parameters: ignore, ist if adaptive model
	 */
	D3P_CONTROL,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore, ist if adaptive model
	 */
	D3P_NUM_EXTRA_CONTROL,
	/**
	 * conversion: int
	 * length    : D3P_NUM_EXTRA_CONTROL
	 * parameters: ignore, ist if adaptive model
	 */
	D3P_EXTRA_CONTROL,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	 D3P_HIGHER_ORDER_ELEMENT_PART_VERSION,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	 D3P_NUM_HIGHER_ORDER_ELEMENT_PART,
	 /**
	 * conversion: D3P_HELM_PART_DATE
	 * length    : D3P_NUM_HIGHER_ORDER_ELEMENT_PART
	 * parameters: ignore
	 */
	 D3P_HIGHER_ORDER_ELEMENT_PART_DATA,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	 D3P_NUM_MATERIAL_TYPE,
	 /**
	 * conversion: int
	 * length    : D3P_NUM_MATERIAL_TYPE
	 * parameters: ignore
	 */
	 D3P_MATERIAL_TYPE,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ist
	 */
	D3P_NUM_GLOBAL_STATE_DATA,
	/**
	 * conversion: float
	 * length    : D3P_NUM_GLOBAL_STATE_DATA
	 * parameters: ist
	 */
	D3P_GLOBAL_STATE_DATA,
	/**
	 * conversion: __int64 or long long
	 * length    : 1
	 * parameters: ist
	 */
	D3P_NUM_SOLID_STATE_DATA,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID_STATE_DATA
	 * parameters: ist
	 */
	D3P_SOLID_STATE_DATA,
	/**
	 * conversion: __int64 or long long
	 * length    : 1
	 * parameters: ist
	 */
	D3P_NUM_SOLID_THERMAL_STATE_DATA,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SOLID_THERMAL_STATE_DATA
	 * parameters: ist
	 */
	D3P_SOLID_THERMAL_STATE_DATA,
	/**
	 * conversion: __int64 or long long 
	 * length    : 1
	 * parameters: ist
	 */
	D3P_NUM_TSHELL_STATE_DATA,
	/**
	 * conversion: float
	 * length    : D3P_NUM_TSHELL_STATE_DATA
	 * parameters: ist
	 */
	D3P_TSHELL_STATE_DATA,
	/**
	 * conversion: __int64 or long long
	 * length    : 1
	 * parameters: ist
	 */
	D3P_NUM_BEAM_STATE_DATA,
	/**
	 * conversion: float
	 * length    : D3P_NUM_BEAM_STATE_DATA
	 * parameters: ist
	 */
	D3P_BEAM_STATE_DATA,
	/**
	 * conversion: __int64 or long long
	 * length    : 1
	 * parameters: ist
	 */
	D3P_NUM_SHELL_STATE_DATA,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SHELL_STATE_DATA
	 * parameters: ist
	 */
	D3P_SHELL_STATE_DATA,
	/**
	 * conversion: __int64 or long long
	 * length    : 1
	 * parameters: ist
	 */
	D3P_NUM_SPH_STATE_DATA,
	/**
	 * conversion: float
	 * length    : D3P_NUM_SPH_STATE_DATA
	 * parameters: ist
	 */
	D3P_SPH_STATE_DATA,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_SPH_VARS_LIST,
	/**
	 * conversion: int
	 * length    : D3P_NUM_SPH_VARS_LIST
	 * parameters: ignore
	 */
	D3P_SPH_VARS_LIST,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_DES_EXTENDED_CONTROL,
	/**
	 * conversion: int
	 * length    : D3P_NUM_DES_EXTENDED_CONTROL
	 * parameters: ignore
	 */
	D3P_DES_EXTENDED_CONTROL,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_DES_VAR_TYPE_LIST,
	/**
	 * conversion: int
	 * length    : D3P_NUM_DES_VAR_TYPE_LIST
	 * parameters: ignore
	 */
	D3P_DES_VAR_TYPE_LIST,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_DES_VAR_NAME_LIST,
	/**
	 * conversion: int
	 * length    : D3P_NUM_DES_VAR_NAME_LIST
	 * parameters: ignore
	 */
	D3P_DES_VAR_NAME_LIST,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ides if necessary
	 */
	D3P_NUM_DES_STATE_DATA,
	/**
	 * conversion: float
	 * length    : D3P_NUM_DES_STATE_DATA
	 * parameters: ist, ides if necessary
	 */
	D3P_DES_STATE_DATA,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_CPM_GEOM_ALL_DATA,
	/**
	 * conversion: float
	 * length    : D3P_NUM_CPM_GEOM_ALL_DATA
	 * parameters: ignore, ist if adaptive model
	 */
	D3P_CPM_GEOM_ALL_DATA,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_CPM_STATE_ALL_DATA,
	/**
	 * conversion: float
	 * length    : D3P_NUM_CPM_STATE_ALL_DATA
	 * parameters: ist
	 */
	D3P_CPM_STATE_ALL_DATA,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_CPM_STATE_GEOM_ALL_DATA,
	/**
	 * conversion: float
	 * length    : D3P_NUM_CPM_STATE_GEOM_DATA
	 * parameters: ist
	 */
	D3P_CPM_STATE_GEOM_ALL_DATA,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_PART_TREE_VARS_LIST,
	/**
	 * conversion: int
	 * length    : D3P_NUM_PART_TREE_VARS_LIST
	 * parameters: ignore
	 */
	D3P_PART_TREE_VARS_LIST,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_PART_TREE_DATA,
	/**
	 * conversion: int
	 * length    : D3P_NUM_PART_TREE_DATA
	 * parameters: ignore
	 */
	D3P_PART_TREE_DATA,
	/**
	 * conversion: __int64 or long long
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_USER_NUMBER_ALL_DATA,
	/**
	 * conversion: char
	 * length    : D3P_NUM_USER_NUMBER_ALL_DATA
	 * parameters: ignore, ist if adaptive model
	 */
	D3P_USER_NUMBER_ALL_DATA,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	D3P_NUM_USER_NUMBER_CONTROL,
	/**
	 * conversion: int
	 * length    : D3P_NUM_USER_NUMBER_CONTROL
	 * parameters: ignore
	 */
	D3P_USER_NUMBER_CONTROL,

	/**
	 * conversion: bool
	 * length    : 1
	 * parameters: ignore
	 */
	INF_HAS_FRINGE_LABEL,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	INF_NUM_FRINGE_LABEL,
	/**
	 * conversion: int
	 * length    : 1
	 * parameters: ignore
	 */
	INF_NUM_FRINGE_LABEL_8CHARACTERS,
	/**
	 * conversion: int
	 * length    : INF_NUM_FRINGE_LABEL
	 * parameters: ignore
	 */
	INF_FRINGE_LABEL_TYPE_LIST,
	/**
	 * conversion: char
	 * length    : INF_NUM_FRINGE_LABEL
	 * parameters: ignore
	 */
	INF_FRINGE_LABEL_LIST,

	/*====================  raw data block end  ====================*/
};
#endif

struct D3P_Vector
{
	float v[3];

	float X() const { return v[0]; }
	float Y() const { return v[1]; }
	float Z() const { return v[2]; }

	bool operator==(const D3P_Vector& src);

	bool isZero(float tol) const;
};

struct D3P_VectorDouble
{
	double v[3];

	double X() const { return v[0]; }
	double Y() const { return v[1]; }
	double Z() const { return v[2]; }

	bool operator==(const D3P_VectorDouble& src);

	bool isZero(double tol) const;
};

struct D3P_Tensor
{
	float t[6];

	float X() const { return t[0]; }
	float Y() const { return t[1]; }
	float Z() const { return t[2]; }
	float XY() const { return t[3]; }
	float YZ() const { return t[4]; }
	float ZX() const { return t[5]; }

	bool operator==(const D3P_Tensor& src);

	bool isZero(float tol) const;
};

struct D3P_Solid
{
	int conn[10];
	int mat;

	int Mat() const { return mat; }
	int Node(int index) const { return conn[index]; }

	bool operator==(const D3P_Solid& src);
};

struct D3P_Tshell
{
	int conn[10];
	int mat;
	int Mat() const { return mat; }
	int Node(int index) const { return conn[index]; }

	bool operator==(const D3P_Tshell& src);
};

struct D3P_Beam 
{ 
	int conn[2];
	int third;
	int w_int; 
	int h_int;
	int mat; 
	int Mat() const { return mat; }
	int Node(int index) const { return conn[index]; }

	bool operator==(const D3P_Beam& src);
};

struct D3P_Shell
{
	int conn[8];
	int mat;
	int Mat() const { return mat; }
	int Node(int index) const { return conn[index]; }

	bool operator==(const D3P_Shell& src);
};

struct D3P_Sph
{ 
	int id;
	unsigned int mat;
	int Mat() const { return mat; }
	int Id() const { return id; }

	bool operator==(const D3P_Sph& src);
};

struct D3P_VAR
{
    int type; //> 1: integer; 2: float
    char name[16];
	std::string Name() const { return name; }
	int Type() const { return type; }

	bool operator==(const D3P_VAR& src);
};

struct D3P_SOLIDTET
{
	int   conn[4];
	int   mat;
	int Mat() const { return mat; }
	int Node(int index) const { return conn[index]; }

	bool operator==(const D3P_SOLIDTET& src);
};

struct D3P_SOLIDFACE
{
	int   conn[4];
	int   mat;
	int Mat() const { return mat; }
	int Node(int index) const { return conn[index]; }

	bool operator==(const D3P_SOLIDFACE& src);
};

struct D3P_SOLIDPYRAMID
{
	int conn[5];
	int eid;
	int Id() const { return eid; }
	int Node(int index) const { return conn[index]; }

	bool operator==(const D3P_SOLIDPYRAMID& src);
};

struct D3P_SOLIDWEDGE
{
	int conn[6];
	int eid;
	int Id() const { return eid; }
	int Node(int index) const { return conn[index]; }

	bool operator==(const D3P_SOLIDWEDGE& src);
};

struct D3P_OLDSOLIDELE
{
	int conn[8];
	int mat;
	int Mat() const { return mat; }
	int Node(int index) const { return conn[index]; }

	bool operator==(const D3P_OLDSOLIDELE& src);
};

struct D3P_TRIAELE
{
	int conn[3];
	int mat;
	int Mat() const { return mat; }
	int Node(int index) const { return conn[index]; }

	bool operator==(const D3P_TRIAELE& src);
};

struct D3P_SEGMENT2
{
	int conn[2];
	int mat;
	int Mat() const { return mat; }
	int Node(int index) const { return conn[index]; }

	bool operator==(const D3P_SEGMENT2& src);
};

struct D3P_DES
{
	int id;
	int mat;
	float radius;
	float mass;
	float inertia;
	int Id() const { return id; }
	int Mat() const { return mat; }
	float Radius() const { return radius; }
	float Mass() const { return mass; }
	float Inertia() const { return inertia; }

	bool operator==(const D3P_DES& src);
};

struct D3P_AIRBAG_INFO
{
	int bagid;
	int startn;
	int npart;
	int ngas;
	int nchamber;
};

struct D3P_SegmentOfRoadSurf
{
	int conn[4];

	int Node(int index) const { return conn[index]; }
	bool operator==(const D3P_SegmentOfRoadSurf& src);
};

struct D3P_Control {
#ifdef CRAY
	char title[80]; /* 0-9  */
#else
#ifdef __DOUBLE_VERSION__
	char title[80]; /* 0-9  */
#else
	char title[40]; /* 0-9  */
#endif
#endif
	int  runtime;		/* 10   */
	int  date;		/* 11   */
	/* file_type_id
	 * d3plot=1,d3drlf=2,d3thdt=3,intfor=4,d3part=5,blstfor=6
	 * d3cpm=7,d3ale=8,d3eigv=11,d3mode=12,d3iter=13,d3ssd=21
	 * d3pcm=22,d3psd=23,d3rms=24,d3ftg=25,d3acs=26 */
	int  machine;		/* 12   version=1000000+svn number */
	int  code;		/* 13   release number */
	float version;		/* 14	floating point number >= 960.0 */
	int  ndim;		/* 15	number of dimensions + flags */
	int  numnp;		/* 16	number of nodal points */
	int  icode;		/* 17	analysis code type */
	int  nglbv;		/* 18	number of global variables */
	int  it;			/* 19	temperature  flag */
	int  iu;			/* 20	geometry flag */
	int  iv;			/* 21   velocity flag */
	int  ia;			/* 22	acceleration flag */
	int  nel8;		/* 23	number of brick elements */
	int  nummat8;		/* 24	number of brick materials */
	int  numds;              /* 25   number of node history blocks */
	int  numst;              /* 26   number of element history blocks */
	int  nv3d;		/* 27	number of brick variables */
	int  nel2;		/* 28	number of beam elements */
	int  nummat2;		/* 29	number of beam materials */
	int  nv1d;		/* 30	number of beam variables */
	int  nel4;		/* 31	number of shell elements */
	int  nummat4;		/* 32	number of shell materials */
	int  nv2d;		/* 33	number of shell variables */
	int  neiph;		/* 34	number of brick history variables */
	int  neips;		/* 35	number of shell history variables */
	int  maxint;		/* 36	max shell LS_INTEGER points + flags */
	int  nmsph;		/* 37	number of sph nodes */
	int  ngpsph;		/* 38	number of sph materials */
	int  narbs;		/* 39	size of arbitrary numbering array */
	int  nelt;		/* 40	number of thick shell elements */
	int  nummatt;		/* 41	number of thick shell material */
	int  nv3dt;		/* 42	number of thick shell variables */
	int  ioshl[4];		/* 43-46 output reduction flags */
	int  numfluidpart;	/* 47   number of fluid parts */
	int  ncfdv1;             /* 48   flag for Navier-Stokes variables */
	int  ncfdv2;             /* 49   flag for Navier-Stokes variables */
	int  nadapt;             /* 50   number adapted element parents */
	int  nmmat;              /* 51   number of materials */
	int  numfluid;		/* 52   number of fluid materials for mix zones */
	int  inn;                /* 53   control accuracy flags */
	int  npefg;              /* 54   number of efg nodes */
	int  nel48;              /* 55   number of 8 node shell elements */
	int  idtdt;		/* 56   Termal DT/dt flag */
	int  extra;              /* 57   number of extra control words */
	int  nstp;               /* 58   number of sph  history blocks */
	int  iflagd;             /* 59   number of node history blocks + 1000 */
	int  nsth;               /* 60   number of brick history blocks */
	int  nstb;               /* 61   number of beam history blocks */
	int  nsts;               /* 62   number of shell history blocks */
	int  nstt;               /* 63   number of thick shell history blocks */
};

struct D3P_HELM_PART_DATA
{
	int pid;     /* part index */
	int mtype;   /* material model */
	int ieos;    /* equation of state */
	int etype;   /* element type: solid=2 */
	int eform;   /* element formulation */
	int nelp;    /* number of elements in part */
	int nmnp;    /* number of nodes in element */
	int ngpout;  /* number integration points per element */
	int lengp;   /* number data values per point */
	int nhisv;   /* number of history variables */
	int istrn;   /* strain output flag */
};

struct D3P_RBodyMotion
{
    float x[3], rx[9], /* current position and rotation matrix */
		  v[3], rv[3], /* velocity: translation and rotation */
		  a[3], ra[3]; /* acceleration: translation and rotation */

	float Pos(int index) { return x[index]; }
	float Rotation(int index) { return rx[index]; }
	float Velocity(int index) { return v[index]; }
	float RotationVelocity(int index) { return rv[index]; }
	float Acceleration(int index) { return a[index]; }
	float RotationAcceleration(int index) { return ra[index]; }

	bool operator==(const D3P_RBodyMotion& src);
};

struct D3P_RBodyMotionDouble
{
	double x[3], rx[9], /* current position and rotation matrix */
		   v[3], rv[3], /* velocity: translation and rotation */
		   a[3], ra[3]; /* acceleration: translation and rotation */

	double Pos(int index) { return x[index]; }
	double Rotation(int index) { return rx[index]; }
	double Velocity(int index) { return v[index]; }
	double RotationVelocity(int index) { return rv[index]; }
	double Acceleration(int index) { return a[index]; }
	double RotationAcceleration(int index) { return ra[index]; }

	bool operator==(const D3P_RBodyMotionDouble& src);
};

struct D3P_SolidExtra20 {
	int eid;
	int midn[12];

	int ElementID() { return eid; }
	int MidNode(int index) { return midn[index]; }

	bool operator==(const D3P_SolidExtra20& src);
};

struct D3P_SolidExtra27 {
	int eid;
	int midn[19];

	int ElementID() { return eid; }
	int MidNode(int index) { return midn[index]; }

	bool operator==(const D3P_SolidExtra27& src);
};

struct D3P_PartTitle {
	char pname[80];
	int  pid;

	std::string GetName()const { return pname; }
	int GetID() const { return pid; }
	bool operator==(const D3P_PartTitle& src);
};

/**
 * parameter to call D3plotReader::GetData, only specific those member variables you are interesting, otherwise, ignore this
 */
struct D3P_Parameter
{
	/**
	 * the state number, start from 0 and default is -1
	 * the frequency number for frequency domain files.
	 */
	int ist; 
	/**
	 * the integration point, range in [0, MAXINT), and default is -1
	 */
	int ipt;
	/**
	 * the index of part, start from 0 and default is -1
	 */
	int ipart;
	/**
	 * the user id of part
	 */
	int ipart_user;
	/**
	 * the index of rigid wall, start from 0 and default is -1
	 */
	int i_rigid_wall;
	/**
	 * the index of the des data, start from 0 and default is -1
	 */
	int ides; 
	/**
	 * the index of history variables, start from 0(sequence number)
	 */
	int ihv;
	/**
	 * the index of the multisolver domain, start from 0 and default is -1
	 */
	int index_multisolver;
	/**
	 * the index of the multisolver var, start from 0 and default is -1
	 */
	int id_var_multisolver;
	/**
	 * the index of the user id, default is -1
	 */
	int iuser;
	/**
	 * for d3atv and d3acc files, it is used to be the value of field point
	 */
	int ifieldpoint;
	/**
	 * the data option, currently used for frequency domain data, 0-defult, 1-amplitude, 2-phase angle
	 */
	int option;
	/**
	 * ale fulid group id, start from 1
	 */
	int id_fluid_group;
	/**
	 * name of output variables, currently used by DES and CPM data, default is empty
	 */
    const char* var_name;
	/**
	 * only for d3lsda(element variable), start from 0
	 */
	int icomp;
    /**
     * part user id set
     */
    std::vector<int> ipartset_user;
	/**
	 * the index of road surface, start from 0
	 */
	int isurface;
	/**
	 * the index of road body, start from 0
	 */
	int i_rigid_body;
	/**
	 * the index of minimum entity, start from 0
	 */
	int idmin;
	/**
	 * the index of maximum entity, start from 0
	 */
	int idmax;

	D3P_Parameter() : ist(-1), ipt(-1), ipart(-1), ipart_user(-1), i_rigid_wall(-1), 
		ides(-1), ihv(-1), index_multisolver(-1), id_var_multisolver(-1), iuser(-1), ifieldpoint(-1), option(0), id_fluid_group(-1), var_name(""), 
		icomp(-1), isurface(-1), i_rigid_body(-1), idmin(-1), idmax(-1)
	{
	}
};

class D3plotReaderImp;
class READERAPI D3plotReader
{
public:
	D3plotReader(const char* name, const char* readerType = "d3plot");
	~D3plotReader();
	
public:
	bool GetData(D3P_DataType type, char* value, const D3P_Parameter& param = D3P_Parameter());
    void Close();

	bool WriteLsdaFile(const char* filename, const char* configfilename = "");

	void SetMessageLevel(D3P_MessageType type);

private:
	D3plotReaderImp*  _imp;
	D3P_MessageType _messageType;
//private:
//	D3plotReader(const D3plotReader&);
//	D3plotReader& operator=(const D3plotReader&);

public:
	int                           GetDataInt(D3P_DataType type, const D3P_Parameter& param = D3P_Parameter());
    bool                          GetDataBool(D3P_DataType type, const D3P_Parameter& param = D3P_Parameter());
    float                         GetDataFloat(D3P_DataType type, const D3P_Parameter& param = D3P_Parameter());
    std::string                   GetDataString(D3P_DataType type, const D3P_Parameter& param = D3P_Parameter());
    D3P_Vector                    GetDataVector(D3P_DataType type, const D3P_Parameter& param = D3P_Parameter());
    std::vector<int>              GetDataIntArray(D3P_DataType type, const D3P_Parameter& param = D3P_Parameter());
    std::vector<float>            GetDataFloatArray(D3P_DataType type, const D3P_Parameter& param = D3P_Parameter());
    std::vector<D3P_Vector>       GetDataVectorArray(D3P_DataType type, const D3P_Parameter& param = D3P_Parameter());
    std::vector<D3P_VectorDouble> GetDataVectorDoubleArray(D3P_DataType type, const D3P_Parameter& param = D3P_Parameter());
    std::vector<D3P_Tensor>       GetDataTensorArray(D3P_DataType type, const D3P_Parameter& param = D3P_Parameter());
    std::vector<D3P_VAR>          GetDataVarArray(D3P_DataType type, const D3P_Parameter& param = D3P_Parameter());
    std::vector<D3P_Solid>        GetDataSolidArray(const D3P_Parameter& param = D3P_Parameter());
    std::vector<D3P_Tshell>       GetDataTshellArray(const D3P_Parameter& param = D3P_Parameter());
    std::vector<D3P_Beam>         GetDataBeamArray(const D3P_Parameter& param = D3P_Parameter());
    std::vector<D3P_Shell>        GetDataShellArray(const D3P_Parameter& param = D3P_Parameter());
    std::vector<D3P_Sph>          GetDataSphArray(const D3P_Parameter& param = D3P_Parameter());
    std::vector<D3P_DES>          GetDataDesArray(const D3P_Parameter& param = D3P_Parameter());
    std::vector<D3P_Solid>	      GetDataMSSolidArray(const D3P_Parameter& param = D3P_Parameter());
    std::vector<D3P_Shell>	      GetDataMSShellArray(const D3P_Parameter& param = D3P_Parameter());
    std::vector<D3P_Beam>	      GetDataMSBeamArray(const D3P_Parameter& param = D3P_Parameter());
	std::vector<D3P_Shell>        GetDataSegmentArray(const D3P_Parameter& param = D3P_Parameter());
	std::vector<D3P_SegmentOfRoadSurf>     GetDataSegmentOfRoadSurfArray(const D3P_Parameter& param = D3P_Parameter());
	std::vector<D3P_RBodyMotion> GetDataRBodyMotionArray(const D3P_Parameter& param = D3P_Parameter());
	std::vector<D3P_RBodyMotionDouble> GetDataRBodyMotionDoubleArray(const D3P_Parameter& param = D3P_Parameter());

	D3P_INT64 GetDataLength(D3P_DataType type, const D3P_Parameter& param = D3P_Parameter());
};

class D3plotExceptionImp;
class D3plotException : public std::runtime_error
{
public:
	explicit D3plotException(const std::string& msg, D3P_ReturnType ret = D3P_ERROR)
		: std::runtime_error(msg), _ret(ret){}

public:
	D3P_ReturnType GetReturnType() const { return _ret; }
private:
	D3P_ReturnType _ret;
};

class LSDAWriterException : public std::runtime_error
{
public:
	explicit LSDAWriterException(const std::string& msg);
};

READERAPI const char* GetLSReaderVersion();
#endif


