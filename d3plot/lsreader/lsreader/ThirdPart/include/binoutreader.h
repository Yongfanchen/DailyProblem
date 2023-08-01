#ifndef  __BINOUTREADER__H
#define  __BINOUTREADER__H

#include <string>
#include <vector>

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

#ifndef __BINOUT_DATA_TYPE_ENUMERATIONS__
#define __BINOUT_DATA_TYPE_ENUMERATIONS__

enum BINOUT_IdType
{
	/*  initial value for idtype*/
	BINOUT_IDTYPE_NONE,

	/*  ID type in Elout branch*/
	BINOUT_ELOUT_ID_BEAM,
	BINOUT_ELOUT_ID_SHELL,
	BINOUT_ELOUT_ID_SOLID,
	BINOUT_ELOUT_ID_TSHELL,
	/*  ID type in Swforc branch*/
	BINOUT_SWFORC_ID_CONSTRAINT,
	BINOUT_SWFORC_ID_WELD,
	BINOUT_SWFORC_ID_BEAM,
	BINOUT_SWFORC_ID_SOLID,
	BINOUT_SWFORC_ID_NONNODAL_CONSTRAINT,
	BINOUT_SWFORC_ID_SOLID_ASSEMBLY,

	/*  ID type in Abstat branch*/
	BINOUT_ABSTAT_ID_AIRBAG,
	BINOUT_ABSTAT_ID_MATERIAL,

	/*  ID type in Abstat_pbm branch*/
	BINOUT_ABSTAT_PBM_ID_PBLAST,
	BINOUT_ABSTAT_PBM_ID_PART,

	/*  ID type in Nodfor branch*/
	BINOUT_NODFOR_ID_NODE,
	BINOUT_NODFOR_ID_GROUP,

	/* ID type in rcforc branch*/
	BINOUT_RCFORC_ID_MASTER,
	BINOUT_RCFORC_ID_SLAVE,

	/* ID type in sbtout branch*/
	BINOUT_SBTOUT_ID_BELT,
	BINOUT_SBTOUT_ID_RETRACTOR,
	BINOUT_SBTOUT_ID_SLIPRING,

	/*ID type in bndout branch*/
	BINOUT_BNDOUT_ID_DISCRETENODES,
	BINOUT_BNDOUT_ID_DISCRETERIGIDBODIES,
	BINOUT_BNDOUT_ID_PRESSURE,
	BINOUT_BNDOUT_ID_VELOCITYNODES,
	BINOUT_BNDOUT_ID_VELOCITYRIGIDBODIES,
	BINOUT_BNDOUT_ID_ORIENTATIONRIGIDBODIES,

	/*ID type in nbndout branch*/
	BINOUT_NBNDOUT_ID_DISCRETENODES,
	BINOUT_NBNDOUT_ID_DISCRETERIGIDBODIES,
	BINOUT_NBNDOUT_ID_PRESSURE,
	BINOUT_NBNDOUT_ID_VELOCITYNODES,
	BINOUT_NBNDOUT_ID_VELOCITYRIGIDBODIES,
	BINOUT_NBNDOUT_ID_ORIENTATIONRIGIDBODIES,

	/*ID type in jntforc branch*/
	BINOUT_JNTFORC_ID_JOINTS,
	BINOUT_JNTFORC_ID_STIFFNESS_TRANSLATIONAL,
	BINOUT_JNTFORC_ID_STIFFNESS_GENERALIZED,

	/*ID type in spcforc*/
	BINOUT_SPCFORC_SETID,
	BINOUT_SPCFORC_ID,

	/*ID type in rwforc*/
	BINOUT_RWFORC_ID_FORCES,
	BINOUT_RWFORC_ID_TRANSDUCER,
	BINOUT_RWFORC_ID_WALL,

	/*ID type in nodfor_ssd */
	BINOUT_NODFOR_SSD_ID_NODE,
	BINOUT_NODFOR_SSD_ID_GROUP,

	/*ID type in elout_ssd*/
	BINOUT_ELOUT_SSD_ID_BEAM,
	BINOUT_ELOUT_SSD_ID_SOLID,
	BINOUT_ELOUT_SSD_ID_TSHELL,
	BINOUT_ELOUT_SSD_ID_SHELL,

	/*ID type in eloutdet*/
	BINOUT_ELOUTDET_ID_SOLID,
	BINOUT_ELOUTDET_ID_SHELL,
	BINOUT_ELOUTDET_ID_TSHELL,
	BINOUT_ELOUTDET_ID_NODAVG,

	/*ID type in abstat_cpm*/
	BINOUT_ABSTATCPM_ID_BAG,
	BINOUT_ABSTATCPM_ID_PART,
	BINOUT_ABSTATCPM_ID_SPECIES,
	BINTOU_ABSTATCPM_ID_CHAMBER,

	/*ID type in elout_psd*/
	BINOUT_ELOUT_PSD_ID_BEAM,
	BINOUT_ELOUT_PSD_ID_SOLID,
	BINOUT_ELOUT_PSD_ID_TSHELL,
	BINOUT_ELOUT_PSD_ID_SHELL,

	/*ID type in elout_spcm*/
	BINOUT_ELOUT_SPCM_ID_BEAM,
	BINOUT_ELOUT_SPCM_ID_SOLID,
	BINOUT_ELOUT_SPCM_ID_TSHELL,
	BINOUT_ELOUT_SPCM_ID_SHELL,
};
enum BINOUT_DataTypeOption
{
	/* initial value for option*/
	BINOUT_DATATYPE_GENERAL,

	/* values for nodout_ssd,nodfor_ssd,elout_ssd files */
	BINOUT_DATATYPE_AMPLITUDE,
	BINOUT_DATATYPE_PHASEANGLE,
	BINOUT_DATATYPE_REAL,
	BINOUT_DATATYPE_IMAGINARY,
	BINOUT_DATATYPE_MODALCONTRIBUTION,

	/*eloutdet ipt or nqt*/
	BINOUT_DATATYPE_ELOUTDET_INTEGRATION_POINTS,
	BINOUT_DATATYPE_ELOUTDET_NODAL_POINTS,

	/*elout lower or upper*/
	BINOUT_DATATYPE_ELOUT_LOWER,
	BINOUT_DATATYPE_ELOUT_UPPER,

};
enum BINOUT_DataType
{
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NUM_BRANCH,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_NUM_BRANCH
	* parameters: ignore
	*/
	BINOUT_BRANCHES,

	/*-----------------------------------------abstat branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_ABSTAT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_ABSTAT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_ABSTAT_X,

	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_ABSTAT_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_ABSTAT_NUM_ID
	* parameters: ignore
	*/
	BINOUT_ABSTAT_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_ABSTAT_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_ABSTAT_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_ABSTAT_COMPONENTS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_ABSTAT_NUM_MATID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_ABSTAT_NUM_MATID
	* parameters: ignore
	*/
	BINOUT_ABSTAT_MAT_IDS,
	/**
	* conversion: double
	* length    : BINOUT_ABSTAT_NUM_TIMESTEP
	* parameters: id, idtype: BINOUT_ABSTAT_ID_AIRBAG or BINOUT_ABSTAT_ID_MATERIAL
	*/
	BINOUT_ABSTAT_AREA_BLOCKED,
	BINOUT_ABSTAT_AREA_UNBLOCKED,
	BINOUT_ABSTAT_LEAKAGE,
	BINOUT_ABSTAT_DENSITY,
	BINOUT_ABSTAT_DM_DT_IN,
	BINOUT_ABSTAT_DM_DT_OUT,
	BINOUT_ABSTAT_DM_DT_OUTP,
	BINOUT_ABSTAT_DM_DT_OUTV,
	BINOUT_ABSTAT_DM_IN,
	BINOUT_ABSTAT_DM_OUT,
	BINOUT_ABSTAT_DM_OUTP,
	BINOUT_ABSTAT_DM_OUTV,
	BINOUT_ABSTAT_GAS_TEMP,
	BINOUT_ABSTAT_INTERNAL_ENERGY,
	BINOUT_ABSTAT_PRESSURE,
	BINOUT_ABSTAT_REACTION,
	BINOUT_ABSTAT_AREA_SURFACE,
	BINOUT_ABSTAT_TOTAL_MASS,
	BINOUT_ABSTAT_VOLUME,

	/*-----------------------------------------abstat_pbm branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_ABSTAT_PBM_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_ABSTAT_PBM_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_ABSTAT_PBM_X,

	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_ABSTAT_PBM_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_ABSTAT_PBM_NUM_ID
	* parameters: ignore
	*/
	BINOUT_ABSTAT_PBM_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_ABSTAT_PBM_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_ABSTAT_PBM_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_ABSTAT_PBM_COMPONENTS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_ABSTAT_PBM_NUM_PARTID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_ABSTAT_PBM_NUM_PARTID
	* parameters: ignore
	*/
	BINOUT_ABSTAT_PBM_PART_IDS,

	/**
	* conversion: double
	* length    : BINOUT_ABSTAT_PBM_NUM_TIMESTEP
	* parameters: id, idtype: BINOUT_ABSTAT_PBM_ID_PBLAST or BINOUT_ABSTAT_PBM_ID_PART
	*/
	BINOUT_ABSTAT_PBM_AIR_INTER_E,
	BINOUT_ABSTAT_PBM_AIR_TRANS_E,
	BINOUT_ABSTAT_PBM_DETONATION_PRODUCT_INTER_E,
	BINOUT_ABSTAT_PBM_DETONATION_PRODUCT_TRANS_E,
	BINOUT_ABSTAT_PBM_OUTSIDE_DOMAIN_INTER_E,
	BINOUT_ABSTAT_PBM_OUTSIDE_DOMAIN_TRANS_E,
	BINOUT_ABSTAT_PBM_PRESSURE_AIR,
	BINOUT_ABSTAT_PBM_PRESSURE_DET_PRODUCTS,
	BINOUT_ABSTAT_PBM_PRESSURE_RESULTANT,
	BINOUT_ABSTAT_PBM_SURFACE_AREA,
	BINOUT_ABSTAT_PBM_X_FORCE_AIR,
	BINOUT_ABSTAT_PBM_X_FORCE_DET_PRODUCTS,
	BINOUT_ABSTAT_PBM_X_FORCE_RESULTANT,
	BINOUT_ABSTAT_PBM_Y_FORCE_AIR,
	BINOUT_ABSTAT_PBM_Y_FORCE_DET_PRODUCTS,
	BINOUT_ABSTAT_PBM_Y_FORCE_RESULTANT,
	BINOUT_ABSTAT_PBM_Z_FORCE_AIR,
	BINOUT_ABSTAT_PBM_Z_FORCE_DET_PRODUCTS,
	BINOUT_ABSTAT_PBM_Z_FORCE_RESULTANT,
	/*-----------------------------------------abstat_cpm branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_ABSTATCPM_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_ABSTATCPM_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_ABSTATCPM_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype
	*/
	BINOUT_ABSTATCPM_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_ABSTATCPM_NUM_ID
	* parameters: idtype
	*/
	BINOUT_ABSTATCPM_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype
	*/
	BINOUT_ABSTATCPM_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_ABSTATCPM_NUM_COMPONENT
	* parameters: idtype
	*/
	BINOUT_ABSTATCPM_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_ABSTATCPM_NUM_TIMESTEP
	* parameters: idtype = BINOUT_ABSTATCPM_ID_BAG, BINTOU_ABSTATCPM_ID_CHAMBER
	*/
	BINOUT_ABSTATCPM_VOLUME,
	BINOUT_ABSTATCPM_PRESSURE,
	BINOUT_ABSTATCPM_INTERNAL_ENERGY,
	BINOUT_ABSTATCPM_DM_DT_IN,
	BINOUT_ABSTATCPM_DENSITY,
	BINOUT_ABSTATCPM_DM_DT_OUT,
	BINOUT_ABSTATCPM_TOTAL_MASS,
	BINOUT_ABSTATCPM_GAS_TEMP,
	BINOUT_ABSTATCPM_SURFACE_AREA,
	BINOUT_ABSTATCPM_REACTION,
	BINOUT_ABSTATCPM_INFLACTOR_E,
	BINOUT_ABSTATCPM_TRANS_KE,
	/**
	* conversion: double
	* length    : BINOUT_ABSTATCPM_NUM_TIMESTEP
	* parameters: idtype = BINOUT_ABSTATCPM_ID_PART
	*/
	BINOUT_ABSTATCPM_POR_LEAK,
	BINOUT_ABSTATCPM_VENT_LEAK,
	BINOUT_ABSTATCPM_AREA_TOTAL,
	BINOUT_ABSTATCPM_AREA_UNBLOCKED,
	BINOUT_ABSTATCPM_TEMPERATURE,
	BINOUT_ABSTATCPM_PRESP,
	BINOUT_ABSTATCPM_PRESM,
	/**
	* conversion: double
	* length    : BINOUT_ABSTATCPM_NUM_TIMESTEP
	* parameters: idtype = BINOUT_ABSTATCPM_ID_SPECIES
	*/
	BINOUT_ABSTATCPM_NT_SPECIES,
	/**
	* conversion: double
	* length    : BINOUT_ABSTATCPM_NUM_TIMESTEP
	* parameters: idtype = BINTOU_ABSTATCPM_ID_CHAMBER
	*/
	BINOUT_ABSTATCPM_TRANSE,
	/*-----------------------------------------cpm_sensor branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_CPMSENSOR_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_CPMSENSOR_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_CPMSENSOR_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_CPMSENSOR_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_CPMSENSOR_NUM_ID
	* parameters: ignore
	*/
	BINOUT_CPMSENSOR_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_CPMSENSOR_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_CPMSENSOR_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_CPMSENSOR_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_CPMSENSOR_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_CPMSENSOR_AVE_VELX,
	BINOUT_CPMSENSOR_AVE_VELY,
	BINOUT_CPMSENSOR_AVE_VELZ,
	BINOUT_CPMSENSOR_AVE_VELR,
	BINOUT_CPMSENSOR_TEMP,
	BINOUT_CPMSENSOR_RHO,
	BINOUT_CPMSENSOR_PRESSURE,
	BINOUT_CPMSENSOR_SENSOR_X,
	BINOUT_CPMSENSOR_SENSOR_Y,
	BINOUT_CPMSENSOR_SENSOR_Z,
	BINOUT_CPMSENSOR_NPART,
	/*-----------------------------------------pg_sensor branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_PGSENSOR_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_PGSENSOR_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_PGSENSOR_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_PGSENSOR_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_PGSENSOR_NUM_ID
	* parameters: ignore
	*/
	BINOUT_PGSENSOR_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_PGSENSOR_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_PGSENSOR_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_PGSENSOR_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_PGSENSOR_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_PGSENSOR_AVE_VELX,
	BINOUT_PGSENSOR_AVE_VELY,
	BINOUT_PGSENSOR_AVE_VELZ,
	BINOUT_PGSENSOR_AVE_VELR,
	BINOUT_PGSENSOR_TEMP,
	BINOUT_PGSENSOR_RHO,
	BINOUT_PGSENSOR_PRESSURE,
	BINOUT_PGSENSOR_SENSOR_X,
	BINOUT_PGSENSOR_SENSOR_Y,
	BINOUT_PGSENSOR_SENSOR_Z,
	BINOUT_PGSENSOR_NPART,
	/*-----------------------------------------pg_stat branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_PGSTAT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_PGSTAT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_PGSTAT_X,

	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_PGSTAT_NUM_BAG_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_PGSTAT_NUM_BAG_ID
	* parameters: ignore
	*/
	BINOUT_PGSTAT_BAG_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_PGSTAT_NUM_PART_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_PGSTAT_NUM_PART_ID
	* parameters: ignore
	*/
	BINOUT_PGSTAT_PART_IDS,
	/**
	* conversion: double
	* length    : BINOUT_PGSTAT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_PGSTAT_NUM_CHAMBER_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_PGSTAT_NUM_CHAMBER_ID
	* parameters: ignore
	*/
	BINOUT_PGSTAT_CHAMBER_IDS,
	/**
	* conversion: double
	* length    : BINOUT_PGSTAT_NUM_TIMESTEP
	* parameters: id, idtype: BINOUT_ABSTAT_ID_AIRBAG or BINOUT_ABSTAT_ID_MATERIAL
	*/
	BINOUT_PGSTAT_NUM_BAG_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_PGSTAT_NUM_BAG_COMPONENT
	* parameters: ignore
	*/
	BINOUT_PGSTAT_BAG_COMPONENTS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_PGSTAT_NUM_PART_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_PGSTAT_NUM_PART_COMPONENT
	* parameters: ignore
	*/
	BINOUT_PGSTAT_PART_COMPONENTS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_PGSTAT_NUM_CHAMBER_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_PGSTAT_NUM_CHAMBER_COMPONENT
	* parameters: ignore
	*/
	BINOUT_PGSTAT_CHAMBER_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_PGSTAT_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_PGSTAT_PART_PRESSURE,
	BINOUT_PGSTAT_PART_POR_LEAK,
	BINOUT_PGSTAT_PART_VENT_LEAK,
	BINOUT_PGSTAT_PART_AREA_TOT,
	BINOUT_PGSTAT_PART_AREA_UNBLOCKED,
	BINOUT_PGSTAT_PART_TEMPERATURE,
	BINOUT_PGSTAT_PART_PRES_PLUS,
	BINOUT_PGSTAT_PART_PRES_MINUS,

	BINOUT_PGSTAT_BAG_VOLUME,
	BINOUT_PGSTAT_BAG_PRESSURE,
	BINOUT_PGSTAT_BAG_INTERNAL_ENERGY,
	BINOUT_PGSTAT_BAG_DM_DT_IN,
	BINOUT_PGSTAT_BAG_DENSITY,
	BINOUT_PGSTAT_BAG_DM_DT_OUT,
	BINOUT_PGSTAT_BAG_TOTAL_MASS,
	BINOUT_PGSTAT_BAG_GAS_TEMP,
	BINOUT_PGSTAT_BAG_SURFACE_AREA,
	BINOUT_PGSTAT_BAG_REACTION,

	BINOUT_PGSTAT_CHAMBER_VOLUME,
	BINOUT_PGSTAT_CHAMBER_PRESSURE,
	BINOUT_PGSTAT_CHAMBER_INTERNAL_ENERGY,
	BINOUT_PGSTAT_CHAMBER_DM_DT_IN,
	BINOUT_PGSTAT_CHAMBER_DENSITY,
	BINOUT_PGSTAT_CHAMBER_DM_DT_OUT,
	BINOUT_PGSTAT_CHAMBER_TOTAL_MASS,
	BINOUT_PGSTAT_CHAMBER_GAS_TEMP,
	BINOUT_PGSTAT_CHAMBER_SURFACE_AREA,
	BINOUT_PGSTAT_CHAMBER_REACTION,
	BINOUT_PGSTAT_CHAMBER_TRANSE,
	
	/*-----------------------------------------disbout branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DISBOUT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_DISBOUT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_DISBOUT_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DISBOUT_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_DISBOUT_NUM_ID
	* parameters: ignore
	*/
	BINOUT_DISBOUT_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DISBOUT_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_DISBOUT_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_DISBOUT_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_DISBOUT_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_DISBOUT_RELATIVE_DISPLACEMENT_AXIS,
	BINOUT_DISBOUT_RELATIVE_DISPLACEMENT_S,
	BINOUT_DISBOUT_RELATIVE_DISPLACEMENT_T,
	BINOUT_DISBOUT_RELATIVE_ROTATION_AXIS,
	BINOUT_DISBOUT_RELATIVE_ROTATION_S,
	BINOUT_DISBOUT_RELATIVE_ROTATION_T,
	BINOUT_DISBOUT_FORCE_AXIS,
	BINOUT_DISBOUT_FORCE_S,
	BINOUT_DISBOUT_FORCE_T,
	BINOUT_DISBOUT_MOMENET_AXIS,
	BINOUT_DISBOUT_MOMENET_S,
	BINOUT_DISBOUT_MOMENET_T,
	BINOUT_DISBOUT_DIRECTION_AXIS_X,
	BINOUT_DISBOUT_DIRECTION_AXIS_Y,
	BINOUT_DISBOUT_DIRECTION_AXIS_Z,
	BINOUT_DISBOUT_DIRECTION_S_X,
	BINOUT_DISBOUT_DIRECTION_S_Y,
	BINOUT_DISBOUT_DIRECTION_S_Z,
	BINOUT_DISBOUT_DIRECTION_T_X,
	BINOUT_DISBOUT_DIRECTION_T_Y,
	BINOUT_DISBOUT_DIRECTION_T_Z,
	/*-----------------------------------------demflow branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DEMFLOW_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_DEMFLOW_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_DEMFLOW_X,

	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DEMFLOW_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_DEMFLOW_NUM_ID
	* parameters: ignore
	*/
	BINOUT_DEMFLOW_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DEMFLOW_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_DEMFLOW_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_DEMFLOW_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_DEMFLOW_NUM_TIMESTEP
	* parameters: id, idtype
	*/
	BINOUT_DEMFLOW_MFLOW_PLUS,
	BINOUT_DEMFLOW_MFLOW_MINUS,
	BINOUT_DEMFLOW_MFLOW_RESULTANT,
	/*-----------------------------------------demtrh branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DEMTRH_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_DEMTRH_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_DEMTRH_X,

	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DEMTRH_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_DEMTRH_NUM_ID
	* parameters: ignore
	*/
	BINOUT_DEMTRH_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DEMTRH_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_DEMTRH_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_DEMTRH_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_DEMTRH_NUM_TIMESTEP
	* parameters: id, idtype
	*/
	BINOUT_DEMTRH_POSITION_X,
	BINOUT_DEMTRH_POSITION_Y,
	BINOUT_DEMTRH_POSITION_Z,
	BINOUT_DEMTRH_VELOCITY_X,
	BINOUT_DEMTRH_VELOCITY_Y,
	BINOUT_DEMTRH_VELOCITY_Z,
	BINOUT_DEMTRH_STRESS_X,
	BINOUT_DEMTRH_STRESS_Y,
	BINOUT_DEMTRH_STRESS_Z,
	BINOUT_DEMTRH_STRESS_XY,
	BINOUT_DEMTRH_STRESS_YZ,
	BINOUT_DEMTRH_STRESS_ZX,
	BINOUT_DEMTRH_POROSITY,
	BINOUT_DEMTRH_VOID_RATIO,
	BINOUT_DEMTRH_COORD_NUMBER,
	BINOUT_DEMTRH_PRESSURE,
	/*-----------------------------------------pblast_sensor branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_PBLAST_SENSOR_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_PBLAST_SENSOR_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_PBLAST_SENSOR_X,

	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_PBLAST_SENSOR_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_PBLAST_SENSOR_NUM_ID
	* parameters: ignore
	*/
	BINOUT_PBLAST_SENSOR_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_PBLAST_SENSOR_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_PBLAST_SENSOR_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_PBLAST_SENSOR_COMPONENTS,
	/**
	* conversion: int
	* length    : BINOUT_PBLAST_SENSOR_NUM_TIMESTEP
	* parameters: id, idtype
	*/
	BINOUT_PBLAST_SENSOR_COUNTS,
	/**
	* conversion: double
	* length    : BINOUT_PBLAST_SENSOR_NUM_TIMESTEP
	* parameters: id, idtype
	*/
	BINOUT_PBLAST_SENSOR_COORD_X,
	BINOUT_PBLAST_SENSOR_COORD_Y,
	BINOUT_PBLAST_SENSOR_COORD_Z,
	BINOUT_PBLAST_SENSOR_TEMPERATURE,
	BINOUT_PBLAST_SENSOR_DENSITY,
	BINOUT_PBLAST_SENSOR_PRESSURE,
	/*-----------------------------------------pllyout branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_PLLYOUT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_PLLYOUT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_PLLYOUT_X,

	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_PLLYOUT_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_PLLYOUT_NUM_ID
	* parameters: ignore
	*/
	BINOUT_PLLYOUT_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_PLLYOUT_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_PLLYOUT_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_PLLYOUT_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_PLLYOUT_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_PLLYOUT_SLIP,
	BINOUT_PLLYOUT_SLIP_RATE,
	BINOUT_PLLYOUT_RESULTANT_FORCE,
	BINOUT_PLLYOUT_WRAP_ANGLE,

	/*-----------------------------------------sphflow branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SPHFLOW_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_SPHFLOW_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_SPHFLOW_X,

	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SPHFLOW_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_SPHFLOW_NUM_ID
	* parameters: ignore
	*/
	BINOUT_SPHFLOW_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SPHFLOW_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_SPHFLOW_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_SPHFLOW_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_SPHFLOW_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_SPHFLOW_MFLOW_PLUS,
	BINOUT_SPHFLOW_MFLOW_MINUS,
	BINOUT_SPHFLOW_MFLOW_RESULTANT,
	/*-----------------------------------------sphout branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SPHOUT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_SPHOUT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_SPHOUT_X,

	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SPHOUT_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_SPHOUT_NUM_ID
	* parameters: ignore
	*/
	BINOUT_SPHOUT_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SPHOUT_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_SPHOUT_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_SPHOUT_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_SPHOUT_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_SPHOUT_STRESS_X,
	BINOUT_SPHOUT_STRESS_Y,
	BINOUT_SPHOUT_STRESS_Z,
	BINOUT_SPHOUT_STRESS_XY,
	BINOUT_SPHOUT_STRESS_YZ,
	BINOUT_SPHOUT_STRESS_ZX,
	BINOUT_SPHOUT_STRAIN_X,
	BINOUT_SPHOUT_STRAIN_Y,
	BINOUT_SPHOUT_STRAIN_Z,
	BINOUT_SPHOUT_STRAIN_XY,
	BINOUT_SPHOUT_STRAIN_YZ,
	BINOUT_SPHOUT_STRAIN_ZX,
	BINOUT_SPHOUT_DENSITY,
	BINOUT_SPHOUT_RADIUS_OF_INFLUNCE,
	BINOUT_SPHOUT_YIELD,
	BINOUT_SPHOUT_EFFECTIVE_STRESS,
	BINOUT_SPHOUT_TEMPERATURE,
	/**
	* conversion: int
	* length    : BINOUT_SPHOUT_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_SPHOUT_NUMBER_OF_NEIGHBORS,
	BINOUT_SPHOUT_ACT,
	/*-----------------------------------------traleh branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_TRALEH_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_TRALEH_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_TRALEH_X,

	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_TRALEH_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_TRALEH_NUM_ID
	* parameters: ignore
	*/
	BINOUT_TRALEH_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_TRALEH_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_TRALEH_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_TRALEH_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_TRALEH_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_TRALEH_POSITION_X,
	BINOUT_TRALEH_POSITION_Y,
	BINOUT_TRALEH_POSITION_Z,
	BINOUT_TRALEH_VELOCITY_X,
	BINOUT_TRALEH_VELOCITY_Y,
	BINOUT_TRALEH_VELOCITY_Z,
	BINOUT_TRALEH_STRESS_X,
	BINOUT_TRALEH_STRESS_Y,
	BINOUT_TRALEH_STRESS_Z,
	BINOUT_TRALEH_STRESS_XY,
	BINOUT_TRALEH_STRESS_YZ,
	BINOUT_TRALEH_STRESS_ZX,
	BINOUT_TRALEH_EFFECTIVE_PLASTIC_STRAIN,
	BINOUT_TRALEH_DENSITY,
	BINOUT_TRALEH_VOLUME_FRACTION,
	BINOUT_TRALEH_HISTORY_VAR,
	/*-----------------------------------------nodfor branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODFOR_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_NODFOR_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_NODFOR_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODFOR_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_NODFOR_NUM_ID
	* parameters: ignore
	*/
	BINOUT_NODFOR_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODFOR_NUM_GROUPID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_NODFOR_NUM_GROUPID
	* parameters: ignore
	*/
	BINOUT_NODFOR_GROUP_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODFOR_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_NODFOR_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_NODFOR_COMPONENTS,

	/**
	* conversion: double
	* length    : BINOUT_NODFOR_NUM_TIMESTEP
	* parameters: id, idtype=BINOUT_NODFOR_ID_NODE
	*/
	BINOUT_NODFOR_ENERGY,
	BINOUT_NODFOR_FORCE_X,
	BINOUT_NODFOR_FORCE_Y,
	BINOUT_NODFOR_FORCE_Z,
	/**
	* conversion: double
	* length    : BINOUT_NODFOR_NUM_TIMESTEP
	* parameters: id, idtype= BINOUT_NODFOR_ID_GROUP
	*/
	BINOUT_NODFOR_TOTAL_ENERGY,
	BINOUT_NODFOR_TOTAL_FORCE_X,
	BINOUT_NODFOR_TOTAL_FORCE_Y,
	BINOUT_NODFOR_TOTAL_FORCE_Z,
	BINOUT_NODFOR_LOCAL_FORCE_X,
	BINOUT_NODFOR_LOCAL_FORCE_Y,
	BINOUT_NODFOR_LOCAL_FORCE_Z,
	/*-----------------------------------------nodout branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODOUT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_NODOUT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_NODOUT_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODOUT_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_NODOUT_NUM_ID
	* parameters: ignore
	*/
	BINOUT_NODOUT_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODOUT_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_NODOUT_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_NODOUT_COMPONENTS,

	/**
	* conversion: double
	* length    : BINOUT_NODOUT_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_NODOUT_ACCELERATION_RX,
	BINOUT_NODOUT_DISPLACEMENT_RX,
	BINOUT_NODOUT_VELOCITY_RX,
	BINOUT_NODOUT_ACCELERATION_RY,
	BINOUT_NODOUT_DISPLACEMENT_RY,
	BINOUT_NODOUT_VELOCITY_RY,
	BINOUT_NODOUT_ACCELERATION_RZ,
	BINOUT_NODOUT_DISPLACEMENT_RZ,
	BINOUT_NODOUT_VELOCITY_RZ,
	BINOUT_NODOUT_ACCELERATION_X,
	BINOUT_NODOUT_COORDINATE_X,
	BINOUT_NODOUT_DISPLACEMENT_X,
	BINOUT_NODOUT_VELOCITY_X,
	BINOUT_NODOUT_ACCELERATION_Y,
	BINOUT_NODOUT_COORDINATE_Y,
	BINOUT_NODOUT_DISPLACEMENT_Y,
	BINOUT_NODOUT_VELOCITY_Y,
	BINOUT_NODOUT_ACCELERATION_Z,
	BINOUT_NODOUT_COORDINATE_Z,
	BINOUT_NODOUT_DISPLACEMENT_Z,
	BINOUT_NODOUT_VELOCITY_Z,

	/*-----------------------------------------nodouthf branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODOUTHF_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_NODOUTHF_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_NODOUTHF_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODOUTHF_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_NODOUTHF_NUM_ID
	* parameters: ignore
	*/
	BINOUT_NODOUTHF_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODOUTHF_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_NODOUTHF_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_NODOUTHF_COMPONENTS,

	/**
	* conversion: double
	* length    : BINOUT_NODOUTHF_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_NODOUTHF_ACCELERATION_RX,
	BINOUT_NODOUTHF_DISPLACEMENT_RX,
	BINOUT_NODOUTHF_VELOCITY_RX,
	BINOUT_NODOUTHF_ACCELERATION_RY,
	BINOUT_NODOUTHF_DISPLACEMENT_RY,
	BINOUT_NODOUTHF_VELOCITY_RY,
	BINOUT_NODOUTHF_ACCELERATION_RZ,
	BINOUT_NODOUTHF_DISPLACEMENT_RZ,
	BINOUT_NODOUTHF_VELOCITY_RZ,
	BINOUT_NODOUTHF_ACCELERATION_X,
	BINOUT_NODOUTHF_COORDINATE_X,
	BINOUT_NODOUTHF_DISPLACEMENT_X,
	BINOUT_NODOUTHF_VELOCITY_X,
	BINOUT_NODOUTHF_ACCELERATION_Y,
	BINOUT_NODOUTHF_COORDINATE_Y,
	BINOUT_NODOUTHF_DISPLACEMENT_Y,
	BINOUT_NODOUTHF_VELOCITY_Y,
	BINOUT_NODOUTHF_ACCELERATION_Z,
	BINOUT_NODOUTHF_COORDINATE_Z,
	BINOUT_NODOUTHF_DISPLACEMENT_Z,
	BINOUT_NODOUTHF_VELOCITY_Z,
	/*-----------------------------------------elout branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = BINOUT_ELOUT_ID_BEAM,BINOUT_ELOUT_ID_SHELL,BINOUT_ELOUT_ID_SOLID or BINOUT_ELOUT_ID_TSHELL,
	*/
	BINOUT_ELOUT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_ELOUT_NUM_TIMESTEP
	* parameters: idtype = BINOUT_ELOUT_ID_BEAM,BINOUT_ELOUT_ID_SHELL,BINOUT_ELOUT_ID_SOLID or BINOUT_ELOUT_ID_TSHELL,
	*/
	BINOUT_ELOUT_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = BINOUT_ELOUT_ID_BEAM,BINOUT_ELOUT_ID_SHELL,BINOUT_ELOUT_ID_SOLID or BINOUT_ELOUT_ID_TSHELL,
	*/
	BINOUT_ELOUT_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_ELOUT_NUM_ID
	* parameters: idtype = BINOUT_ELOUT_ID_BEAM,BINOUT_ELOUT_ID_SHELL,BINOUT_ELOUT_ID_SOLID or BINOUT_ELOUT_ID_TSHELL,
	*/
	BINOUT_ELOUT_IDS,

	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = BINOUT_ELOUT_ID_BEAM,BINOUT_ELOUT_ID_SHELL,BINOUT_ELOUT_ID_SOLID or BINOUT_ELOUT_ID_TSHELL,
	*/
	BINOUT_ELOUT_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_ELOUT_NUM_COMPONENT
	* parameters: idtype = BINOUT_ELOUT_ID_BEAM,BINOUT_ELOUT_ID_SHELL,BINOUT_ELOUT_ID_SOLID or BINOUT_ELOUT_ID_TSHELL,
	*/
	BINOUT_ELOUT_COMPONENTS,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = BINOUT_ELOUT_ID_BEAM,BINOUT_ELOUT_ID_SHELL,BINOUT_ELOUT_ID_SOLID or BINOUT_ELOUT_ID_TSHELL,
	*/
	BINOUT_ELOUT_NUM_IPT,
	/**
	* conversion: unsigned int
	* length    : BINOUT_ELOUT_NUM_IPT
	* parameters: idtype = BINOUT_ELOUT_ID_BEAM,BINOUT_ELOUT_ID_SHELL,BINOUT_ELOUT_ID_SOLID or BINOUT_ELOUT_ID_TSHELL,
	*/
	BINOUT_ELOUT_IPTS,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = BINOUT_ELOUT_ID_BEAM,BINOUT_ELOUT_ID_SHELL,BINOUT_ELOUT_ID_SOLID or BINOUT_ELOUT_ID_TSHELL,
	*/
	BINOUT_ELOUT_NUM_NPL,
	/**
	* conversion: unsigned int
	* length    : BINOUT_ELOUT_NUM_NPL
	* parameters: idtype = BINOUT_ELOUT_ID_BEAM,BINOUT_ELOUT_ID_SHELL,BINOUT_ELOUT_ID_SOLID or BINOUT_ELOUT_ID_TSHELL,
	*/
	BINOUT_ELOUT_NPLS,

	/**
	* conversion: double
	* length    : BINOUT_ELOUT_NUM_TIMESTEP
	* parameters: idtype = BINOUT_ELOUT_ID_BEAM,BINOUT_ELOUT_ID_SHELL,BINOUT_ELOUT_ID_SOLID or BINOUT_ELOUT_ID_TSHELL,id, ipt, npl
	*/
	BINOUT_ELOUT_STRESS_XX,
	BINOUT_ELOUT_STRESS_YY,
	BINOUT_ELOUT_STRESS_ZZ,
	BINOUT_ELOUT_STRESS_XY,
	BINOUT_ELOUT_STRESS_YZ,
	BINOUT_ELOUT_STRESS_ZX,

	BINOUT_ELOUT_YIELD,
	BINOUT_ELOUT_EFFSG,
	BINOUT_ELOUT_PLASTIC_STRAIN,

	BINOUT_ELOUT_STRAIN_XX,
	BINOUT_ELOUT_STRAIN_YY,
	BINOUT_ELOUT_STRAIN_ZZ,
	BINOUT_ELOUT_STRAIN_XY,
	BINOUT_ELOUT_STRAIN_YZ,
	BINOUT_ELOUT_STRAIN_ZX,

	BINOUT_ELOUT_AXIAL,
	BINOUT_ELOUT_SHEAR_S,
	BINOUT_ELOUT_SHEAR_T,
	BINOUT_ELOUT_MOMENT_S,
	BINOUT_ELOUT_MOMENT_T,
	BINOUT_ELOUT_TORSION,

	BINOUT_ELOUT_COEF_LENGTH,
	BINOUT_ELOUT_VISC_FORCE,
	BINOUT_ELOUT_SIGMA_11,
	BINOUT_ELOUT_SIGMA_12,
	BINOUT_ELOUT_SIGMA_31,
	BINOUT_ELOUT_PLASTIC_EPS,

	BINOUT_ELOUT_HISTORY_VAR,
	/*-----------------------------------------ssstat branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SSSTAT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_SSSTAT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_SSSTAT_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SSSTAT_NUM_SYSTEMS,
	/**
	* conversion: unsigned int
	* length    : BINOUT_SSSTAT_NUM_SYSTEMS
	* parameters: ignore
	*/
	BINOUT_SSSTAT_SYSTEM_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SSSTAT_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_SSSTAT_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_SSSTAT_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_SSSTAT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_SSSTAT_TIME_STEP,
	BINOUT_SSSTAT_KIN_ENERGY_G,
	BINOUT_SSSTAT_INT_ENERGY_G,
	BINOUT_SSSTAT_HGL_ENERGY_G,
	/**
	* conversion: double
	* length    : BINOUT_SSSTAT_NUM_TIMESTEP
	* parameters: systemid
	*/
	BINOUT_SSSTAT_KINETIC_ENERGY,
	BINOUT_SSSTAT_INTERNAL_ENERGY,
	BINOUT_SSSTAT_HOURGLASS_ENERGY,
	BINOUT_SSSTAT_MOMENTUM_X,
	BINOUT_SSSTAT_MOMENTUM_Y,
	BINOUT_SSSTAT_MOMENTUM_Z,
	BINOUT_SSSTAT_KINETIC_ENERGY_RATIOS,
	BINOUT_SSSTAT_INTERNAL_ENERGY_RATIOS,
	BINOUT_SSSTAT_TOTALMASS_SUBSYSTEM,
	BINOUT_SSSTAT_MASSCENTER_COORDINATE_X,
	BINOUT_SSSTAT_MASSCENTER_COORDINATE_Y,
	BINOUT_SSSTAT_MASSCENTER_COORDINATE_Z,
	BINOUT_SSSTAT_INERTIA_TENSOR_XX,
	BINOUT_SSSTAT_INERTIA_TENSOR_XY,
	BINOUT_SSSTAT_INERTIA_TENSOR_XZ,
	BINOUT_SSSTAT_INERTIA_TENSOR_YY,
	BINOUT_SSSTAT_INERTIA_TENSOR_YZ,
	BINOUT_SSSTAT_INERTIA_TENSOR_ZZ,
	BINOUT_SSSTAT_PRINCIPAL_INERTIAS_1ST,
	BINOUT_SSSTAT_PRINCIPAL_INERTIAS_2ND,
	BINOUT_SSSTAT_PRINCIPAL_INERTIAS_3RD,
	BINOUT_SSSTAT_PRINCIPAL_INERTIAS_1ST_DIRECTIONS_X,
	BINOUT_SSSTAT_PRINCIPAL_INERTIAS_1ST_DIRECTIONS_Y,
	BINOUT_SSSTAT_PRINCIPAL_INERTIAS_1ST_DIRECTIONS_Z,
	BINOUT_SSSTAT_PRINCIPAL_INERTIAS_2ND_DIRECTIONS_X,
	BINOUT_SSSTAT_PRINCIPAL_INERTIAS_2ND_DIRECTIONS_Y,
	BINOUT_SSSTAT_PRINCIPAL_INERTIAS_2ND_DIRECTIONS_Z,
	BINOUT_SSSTAT_PRINCIPAL_INERTIAS_3RD_DIRECTIONS_X,
	BINOUT_SSSTAT_PRINCIPAL_INERTIAS_3RD_DIRECTIONS_Y,
	BINOUT_SSSTAT_PRINCIPAL_INERTIAS_3RD_DIRECTIONS_Z,
	/*-----------------------------------------glstat branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_GLSTAT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_GLSTAT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_GLSTAT_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_GLSTAT_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_GLSTAT_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_GLSTAT_COMPONENTS,

	/**
	* conversion: int
	* length    : BINOUT_GLSTAT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_GLSTAT_NUMBER_OF_NODES,
	BINOUT_GLSTAT_NUMBER_OF_ELEMENTS,
	BINOUT_GLSTAT_NZC,
	/**
	* conversion: double
	* length    : BINOUT_GLSTAT_TIME_STEP
	* parameters: ignore
	*/
	BINOUT_GLSTAT_TIME_STEP,
	BINOUT_GLSTAT_KINETIC_ENERGY,
	BINOUT_GLSTAT_INTERNAL_ENERGY,
	BINOUT_GLSTAT_RB_STOPPER_ENERGY,
	BINOUT_GLSTAT_SPRING_AND_DAMPER_ENERGY,
	BINOUT_GLSTAT_JOINT_INTERNAL_ENERGY,
	BINOUT_GLSTAT_HOURGLASS_ENERGY,
	BINOUT_GLSTAT_SYSTEM_DAMPING_ENERGY,
	BINOUT_GLSTAT_SLIDING_INTERFACE_ENERGY,
	BINOUT_GLSTAT_EXTERNAL_WORK,
	BINOUT_GLSTAT_ERODED_KINETIC_ENERGY,
	BINOUT_GLSTAT_ERODED_INTERNAL_ENERGY,
	BINOUT_GLSTAT_ERODED_HOURGLASS_ENERGY,
	BINOUT_GLSTAT_TOTAL_ENERGY,
	BINOUT_GLSTAT_ENERGY_RATIO,
	BINOUT_GLSTAT_ENERGY_RATIO_WO_ERODED,
	BINOUT_GLSTAT_GLOBAL_VELOCITY_X,
	BINOUT_GLSTAT_GLOBAL_VELOCITY_Y,
	BINOUT_GLSTAT_GLOBAL_VELOCITY_Z,
	BINOUT_GLSTAT_ADDED_MASS,
	BINOUT_GLSTAT_PERCENT_INCREASE,

	BINOUT_GLSTAT_TOTAL_MASS,
	BINOUT_GLSTAT_MASS_CENTER_X,
	BINOUT_GLSTAT_MASS_CENTER_Y,
	BINOUT_GLSTAT_MASS_CENTER_Z,

	/*-----------------------------------------deforc branch begin----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DEFORC_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_DEFORC_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_DEFORC_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DEFORC_NUM_TRANSLATION_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_DEFORC_NUM_TRANSLATION_ID
	* parameters: ignore
	*/
	BINOUT_DEFORC_TRANSLATION_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DEFORC_NUM_ROTATION_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_DEFORC_NUM_ROTATION_ID
	* parameters: ignore
	*/
	BINOUT_DEFORC_ROTATION_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DEFORC_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_DEFORC_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_DEFORC_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_DEFORC_NUM_TIMESTEP
	* parameters: id = spring/damper number
	*/
	BINOUT_DEFORC_DISPLACEMENT,
	BINOUT_DEFORC_RESULTANT_FORCE,
	BINOUT_DEFORC_FORCE_X,
	BINOUT_DEFORC_FORCE_Y,
	BINOUT_DEFORC_FORCE_Z,

	BINOUT_DEFORC_RELATIVE_ROTATION,
	BINOUT_DEFORC_RESULTANT_MOMENT,
	BINOUT_DEFORC_MOMENT_X,
	BINOUT_DEFORC_MOMENT_Y,
	BINOUT_DEFORC_MOMENT_Z,

	/*-----------------------------------------matsum branch begin------------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_MATSUM_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_MATSUM_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_MATSUM_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_MATSUM_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_MATSUM_NUM_ID
	* parameters: ignore
	*/
	BINOUT_MATSUM_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_MATSUM_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_MATSUM_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_MATSUM_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_MATSUM_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_MATSUM_INTERNAL_ENERGY,
	BINOUT_MATSUM_KINETIC_ENERGY,
	BINOUT_MATSUM_ERODED_INTERNAL_ENERGY,
	BINOUT_MATSUM_ERODED_KINETIC_ENERGY,
	BINOUT_MATSUM_MASS,
	BINOUT_MATSUM_HOURGLASS_ENERGY,
	BINOUT_MATSUM_MOMENTUM_X,
	BINOUT_MATSUM_MOMENTUM_Y,
	BINOUT_MATSUM_MOMENTUM_Z,
	BINOUT_MATSUM_RBVELOCITY_X,
	BINOUT_MATSUM_RBVELOCITY_Y,
	BINOUT_MATSUM_RBVELOCITY_Z,

	/*-----------------------------------------trhist branch begin------------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_TRHIST_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_TRHIST_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_TRHIST_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_TRHIST_NUM_TRACER,
	/**
	* conversion: unsigned int
	* length    : BINOUT_TRHIST_NUM_TRACER
	* parameters: ignore
	*/
	BINOUT_TRHIST_TRACERS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_TRHIST_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_TRHIST_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_TRHIST_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_TRHIST_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_TRHIST_ELEMENT_ID,
	BINOUT_TRHIST_COORDINATE_X,
	BINOUT_TRHIST_COORDINATE_Y,
	BINOUT_TRHIST_COORDINATE_Z,
	BINOUT_TRHIST_VELOCITY_X,
	BINOUT_TRHIST_VELOCITY_Y,
	BINOUT_TRHIST_VELOCITY_Z,
	BINOUT_TRHIST_STRESS_X,
	BINOUT_TRHIST_STRESS_Y,
	BINOUT_TRHIST_STRESS_Z,
	BINOUT_TRHIST_STRESS_XY,
	BINOUT_TRHIST_STRESS_YZ,
	BINOUT_TRHIST_STRESS_ZX,
	BINOUT_TRHIST_EFFECTIVE_PLASTIC_STRAIN,
	BINOUT_TRHIST_REL_VOL,
	BINOUT_TRHIST_RHO,

	/*-----------------------------------------tprint branch begin------------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_TPRINT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_TPRINT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_TPRINT_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_TPRINT_NUM_NODE_ID,
	BINOUT_TPRINT_NUM_PART_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_TPRINT_NUM_ID
	* parameters: ignore
	*/
	BINOUT_TPRINT_NODE_IDS,
	BINOUT_TPRINT_PART_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_TPRINT_NUM_NODE_COMPONENT,
	BINOUT_TPRINT_NUM_PART_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_TPRINT_NUM_NODE_COMPONENT
	* parameters: ignore
	*/
	BINOUT_TPRINT_NODE_COMPONENTS,

	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_TPRINT_NUM_PART_COMPONENT
	* parameters: ignore
	*/
	BINOUT_TPRINT_PART_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_TPRINT_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_TPRINT_TEMPERATURE,
	BINOUT_TPRINT_FLUX_X,
	BINOUT_TPRINT_FLUX_Y,
	BINOUT_TPRINT_FLUX_Z,
	BINOUT_TPRINT_T_TOP,
	BINOUT_TPRINT_T_BOTTOM,
	BINOUT_TPRINT_AVERAGE_PART_TEMPERATURE,
	BINOUT_TPRINT_ENERGY_CHANGE,
	BINOUT_TPRINT_HEAT_GENERATED,

	/*-----------------------------------------ncforc branch start----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NCFORC_NUM_INTERFACE,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_NCFORC_NUM_INTERFACE
	* parameters: ignore
	*/
	BINOUT_NCFORC_INTERFACES,
	/**
	* conversion: int
	* length    : 1
	* parameters: cid = contact id
	*/
	BINOUT_NCFORC_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_NCFORC_NUM_ID
	* parameters: cid = contact id
	*/
	BINOUT_NCFORC_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: cid = contact id
	*/
	BINOUT_NCFORC_NUM_SLAVEID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_NCFORC_NUM_SLAVEID
	* parameters: cid = contact id
	*/
	BINOUT_NCFORC_SLAVE_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: cid = contact id
	*/
	BINOUT_NCFORC_NUM_MASTERID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_NCFORC_NUM_MASTERID
	* parameters: cid = contact id
	*/
	BINOUT_NCFORC_MASTER_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: cid = contact id
	*/
	BINOUT_NCFORC_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_NCFORC_NUM_TIMESTEP
	* parameters: cid = contact id
	*/
	BINOUT_NCFORC_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: cid = contact id
	*/
	BINOUT_NCFORC_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_NCFORC_NUM_COMPONENT,
	* parameters: cid = contact id
	*/
	BINOUT_NCFORC_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_NCFORC_NUM_TIMESTEP
	* parameters: cid = contact id, id = master/slave node id
	*/
	BINOUT_NCFORC_FORCE_X,
	BINOUT_NCFORC_FORCE_Y,
	BINOUT_NCFORC_FORCE_Z,
	BINOUT_NCFORC_PRESSURE,
	BINOUT_NCFORC_COORDINATE_X,
	BINOUT_NCFORC_COORDINATE_Y,
	BINOUT_NCFORC_COORDINATE_Z,

	/*-----------------------------------------rcforc branch begin----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_RCFORC_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_RCFORC_NUM_ID
	* parameters: ignore
	*/
	BINOUT_RCFORC_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_RCFORC_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_RCFORC_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_RCFORC_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_RCFORC_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_RCFORC_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_RCFORC_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_RCFORC_NUM_TIMESTEP
	* parameters: id, idtype: BINOUT_RCFORC_ID_MASTER, BINOUT_RCFORC_ID_SLAVE
	*/
	BINOUT_RCFORC_MASS,
	BINOUT_RCFORC_TIE_AREA,
	BINOUT_RCFORC_TIE_COUNT,
	BINOUT_RCFORC_FORCE_X,
	BINOUT_RCFORC_FORCE_Y,
	BINOUT_RCFORC_FORCE_Z,
	BINOUT_RCFORC_RESULTANT_FORCE,
	BINOUT_RCFORC_MOMENT_X,
	BINOUT_RCFORC_MOMENT_Y,
	BINOUT_RCFORC_MOMENT_Z,
	/*-----------------------------------------secforc branch begin----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SECFORC_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_SECFORC_NUM_ID
	* parameters: ignore
	*/
	BINOUT_SECFORC_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SECFORC_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_SECFORC_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_SECFORC_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SECFORC_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_SECFORC_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_SECFORC_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_SECFORC_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_SECFORC_FORCE_X,
	BINOUT_SECFORC_FORCE_Y,
	BINOUT_SECFORC_FORCE_Z,
	BINOUT_SECFORC_FORCE_TOTAL,
	BINOUT_SECFORC_MOMENT_X,
	BINOUT_SECFORC_MOMENT_Y,
	BINOUT_SECFORC_MOMENT_Z,
	BINOUT_SECFORC_MOMENT_TOTAL,
	BINOUT_SECFORC_CENTROID_X,
	BINOUT_SECFORC_CENTROID_Y,
	BINOUT_SECFORC_CENTROID_Z,
	BINOUT_SECFORC_AREA,
	/*-----------------------------------------dcfail branch begin----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DCFAIL_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_DCFAIL_NUM_ID
	* parameters: ignore
	*/
	BINOUT_DCFAIL_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DCFAIL_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_DCFAIL_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_DCFAIL_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DCFAIL_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_DCFAIL_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_DCFAIL_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_DCFAIL_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_DCFAIL_AREA,
	BINOUT_DCFAIL_BENDING_TERM,
	BINOUT_DCFAIL_EFFECTIVE_STRAIN_RATE,
	BINOUT_DCFAIL_FAILURE_FUNCTION,
	BINOUT_DCFAIL_NORMAL_TERM,
	BINOUT_DCFAIL_SHEAR_TERM,
	BINOUT_DCFAIL_AREA_SOL,
	BINOUT_DCFAIL_AXIAL_FORCE,
	BINOUT_DCFAIL_SHEAR_FORCE,
	BINOUT_DCFAIL_TORSIONAL_MOMENT,
	BINOUT_DCFAIL_BENDING_MOMENT,
	/*-----------------------------------------prtube branch begin----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_PRTUBE_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_PRTUBE_NUM_ID
	* parameters: ignore
	*/
	BINOUT_PRTUBE_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_PRTUBE_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_PRTUBE_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_PRTUBE_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_PRTUBE_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_PRTUBE_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_PRTUBE_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_PRTUBE_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_PRTUBE_AREA,
	BINOUT_PRTUBE_PRESSURE,
	BINOUT_PRTUBE_VELOCITY,
	BINOUT_PRTUBE_DENSITY,
	/*-----------------------------------------gceout branch begin----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_GCEOUT_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_GCEOUT_NUM_ID
	* parameters: ignore
	*/
	BINOUT_GCEOUT_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_GCEOUT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_GCEOUT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_GCEOUT_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_GCEOUT_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_GCEOUT_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_GCEOUT_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_GCEOUT_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_GCEOUT_FORCE_X,
	BINOUT_GCEOUT_FORCE_Y,
	BINOUT_GCEOUT_FORCE_Z,
	BINOUT_GCEOUT_MOMENT_X,
	BINOUT_GCEOUT_MOMENT_Y,
	BINOUT_GCEOUT_MOMENT_Z,
	BINOUT_GCEOUT_FORCE_MAGNITUDE,
	BINOUT_GCEOUT_MOMENT_MAGNITUDE,
	/*-----------------------------------------defgeo branch begin----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DEFGEO_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_DEFGEO_NUM_ID
	* parameters: ignore
	*/
	BINOUT_DEFGEO_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DEFGEO_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_DEFGEO_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_DEFGEO_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DEFGEO_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_DEFGEO_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_DEFGEO_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_DEFGEO_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_DEFGEO_DISPLACEMENT_X,
	BINOUT_DEFGEO_DISPLACEMENT_Y,
	BINOUT_DEFGEO_DISPLACEMENT_Z,
	BINOUT_DEFGEO_DISPLACEMENT_MAX,
	/*-----------------------------------------dem_rcforc branch begin----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DEMRCFORC_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_DEMRCFORC_NUM_ID
	* parameters: ignore
	*/
	BINOUT_DEMRCFORC_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DEMRCFORC_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_DEMRCFORC_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_DEMRCFORC_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DEMRCFORC_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_DEMRCFORC_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_DEMRCFORC_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_DEMRCFORC_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_DEMRCFORC_FORCE_X,
	BINOUT_DEMRCFORC_FORCE_Y,
	BINOUT_DEMRCFORC_FORCE_Z,
	/*-----------------------------------------brngout branch begin----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_BRNGOUT_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_BRNGOUT_NUM_ID
	* parameters: ignore
	*/
	BINOUT_BRNGOUT_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_BRNGOUT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_BRNGOUT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_BRNGOUT_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_BRNGOUT_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_BRNGOUT_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_BRNGOUT_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_BRNGOUT_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_BRNGOUT_FFXG,
	BINOUT_BRNGOUT_FFYG,
	BINOUT_BRNGOUT_FFZG,
	BINOUT_BRNGOUT_FMXG,
	BINOUT_BRNGOUT_FMYG,
	BINOUT_BRNGOUT_FMZG,
	BINOUT_BRNGOUT_FFX,
	BINOUT_BRNGOUT_FFY,
	BINOUT_BRNGOUT_FFZ,
	BINOUT_BRNGOUT_FMX,
	BINOUT_BRNGOUT_FMY,
	BINOUT_BRNGOUT_DXG,
	BINOUT_BRNGOUT_DYG,
	BINOUT_BRNGOUT_DZG,
	BINOUT_BRNGOUT_AXG,
	BINOUT_BRNGOUT_AYG,
	BINOUT_BRNGOUT_AZG,
	BINOUT_BRNGOUT_DXL,
	BINOUT_BRNGOUT_DYL,
	BINOUT_BRNGOUT_DZL,
	BINOUT_BRNGOUT_BXL,
	BINOUT_BRNGOUT_BYL,
	/*-----------------------------------------dbfsi branch begin----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DBFSI_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_DBFSI_NUM_ID
	* parameters: ignore
	*/
	BINOUT_DBFSI_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DBFSI_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_DBFSI_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_DBFSI_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DBFSI_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_DBFSI_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_DBFSI_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_DBFSI_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_DBFSI_FX,
	BINOUT_DBFSI_FY,
	BINOUT_DBFSI_FZ,
	BINOUT_DBFSI_PRES,
	BINOUT_DBFSI_MOUT,
	BINOUT_DBFSI_OBSOLETE,
	BINOUT_DBFSI_GX,
	BINOUT_DBFSI_GY,
	BINOUT_DBFSI_GZ,
	BINOUT_DBFSI_PTMP,
	BINOUT_DBFSI_PDT,
	/*-----------------------------------------sbtout branch begin----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SBTOUT_NUM_BELT_ID,
	/**
	* conversion: usigned int
	* length    : BINOUT_SBTOUT_NUM_BELT_ID
	* parameters: ignore
	*/
	BINOUT_SBTOUT_BELT_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SBTOUT_NUM_RETRACTOR_ID,
	/**
	* conversion: usigned int
	* length    : BINOUT_SBTOUT_NUM_RETRACTOR_ID
	* parameters: ignore
	*/
	BINOUT_SBTOUT_RETRACTOR_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SBTOUT_NUM_SLIPRING_ID,
	/**
	* conversion: usigned int
	* length    : BINOUT_SBTOUT_NUM_SLIPRING_ID
	* parameters: ignore
	*/
	BINOUT_SBTOUT_SLIPRING_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SBTOUT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_SBTOUT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_SBTOUT_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SBTOUT_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_SBTOUT_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_SBTOUT_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_SBTOUT_TIMESTEP
	* parameters: id, idtype: BINOUT_SBTOUT_ID_BELT
	*/
	BINOUT_SBTOUT_BELT_FORCE,
	BINOUT_SBTOUT_BELT_LENGTH,
	/**
	* conversion: double
	* length    : BINOUT_SBTOUT_TIMESTEP
	* parameters: id, idtype: BINOUT_SBTOUT_ID_RETRACTOR
	*/
	BINOUT_SBTOUT_RETRACTOR_FORCE,
	BINOUT_SBTOUT_RETRACTOR_PULL_OUT,
	/**
	* conversion: double
	* length    : BINOUT_SBTOUT_TIMESTEP
	* parameters: id, idtype: BINOUT_SBTOUT_ID_SLIPRING
	*/
	BINOUT_SBTOUT_RING_SLIP,
	/*-----------------------------------------bndout branch begin------------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype
	*/
	BINOUT_BNDOUT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_BNDOUT_NUM_TIMESTEP,
	* parameters: idtype = 	BINOUT_BNDOUT_ID_DISCRETENODES,
	                        BINOUT_BNDOUT_ID_DISCRETERIGIDBODIES,
	                        BINOUT_BNDOUT_ID_PRESSURE,
	                        BINOUT_BNDOUT_ID_VELOCITYNODES,
							BINOUT_BNDOUT_ID_VELOCITYRIGIDBODIES,
							BINOUT_BNDOUT_ID_ORIENTATIONRIGIDBODIES,
	*/
	BINOUT_BNDOUT_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = 	BINOUT_BNDOUT_ID_DISCRETENODES,
	                        BINOUT_BNDOUT_ID_DISCRETERIGIDBODIES,
	                        BINOUT_BNDOUT_ID_PRESSURE,
	                        BINOUT_BNDOUT_ID_VELOCITYNODES,
							BINOUT_BNDOUT_ID_VELOCITYRIGIDBODIES,
							BINOUT_BNDOUT_ID_ORIENTATIONRIGIDBODIES,
	*/
	BINOUT_BNDOUT_NUM_ID,
	/**
	* conversion: usigned int
	* length    : BINOUT_BNDOUT_NUM_ID
	* parameters: idtype = 	BINOUT_BNDOUT_ID_DISCRETENODES,
	                        BINOUT_BNDOUT_ID_DISCRETERIGIDBODIES,
	                        BINOUT_BNDOUT_ID_PRESSURE,
	                        BINOUT_BNDOUT_ID_VELOCITYNODES,
							BINOUT_BNDOUT_ID_VELOCITYRIGIDBODIES,
							BINOUT_BNDOUT_ID_ORIENTATIONRIGIDBODIES,
	*/
	BINOUT_BNDOUT_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = 	BINOUT_BNDOUT_ID_DISCRETENODES,
	                        BINOUT_BNDOUT_ID_DISCRETERIGIDBODIES,
	                        BINOUT_BNDOUT_ID_PRESSURE,
	                        BINOUT_BNDOUT_ID_VELOCITYNODES,
							BINOUT_BNDOUT_ID_VELOCITYRIGIDBODIES,
							BINOUT_BNDOUT_ID_ORIENTATIONRIGIDBODIES,
	*/
	BINOUT_BNDOUT_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_BNDOUT_NUM_COMPONENT
	* parameters: idtype = 	BINOUT_BNDOUT_ID_DISCRETENODES,
	                        BINOUT_BNDOUT_ID_DISCRETERIGIDBODIES,
	                        BINOUT_BNDOUT_ID_PRESSURE,
	                        BINOUT_BNDOUT_ID_VELOCITYNODES,
							BINOUT_BNDOUT_ID_VELOCITYRIGIDBODIES,
							BINOUT_BNDOUT_ID_ORIENTATIONRIGIDBODIES,
	*/
	BINOUT_BNDOUT_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_BNDOUT_NUM_TIMESTEP
	* parameters: id, idtype = 	BINOUT_BNDOUT_ID_DISCRETENODES,
	                        BINOUT_BNDOUT_ID_DISCRETERIGIDBODIES,
	                        BINOUT_BNDOUT_ID_PRESSURE,
	                        BINOUT_BNDOUT_ID_VELOCITYNODES,
							BINOUT_BNDOUT_ID_VELOCITYRIGIDBODIES,
							BINOUT_BNDOUT_ID_ORIENTATIONRIGIDBODIES,
	*/
	BINOUT_BNDOUT_FORCE_X,
	BINOUT_BNDOUT_FORCE_Y,
	BINOUT_BNDOUT_FORCE_Z,
	BINOUT_BNDOUT_ENERGY,
	BINOUT_BNDOUT_MOMENT_X,
	BINOUT_BNDOUT_MOMENT_Y,
	BINOUT_BNDOUT_MOMENT_Z,
	/**
	* conversion: double
	* length    : BINOUT_BNDOUT_NUM_TIMESTEP
	* parameters: idtype = 	BINOUT_BNDOUT_ID_DISCRETENODES,
	                        BINOUT_BNDOUT_ID_DISCRETERIGIDBODIES,
	                        BINOUT_BNDOUT_ID_PRESSURE,
	                        BINOUT_BNDOUT_ID_VELOCITYNODES,
							BINOUT_BNDOUT_ID_VELOCITYRIGIDBODIES,
							BINOUT_BNDOUT_ID_ORIENTATIONRIGIDBODIES,
	*/
	BINOUT_BNDOUT_TOTAL_X,
	BINOUT_BNDOUT_TOTAL_Y,
	BINOUT_BNDOUT_TOTAL_Z,
	BINOUT_BNDOUT_ETOTAL,
	/*-----------------------------------------nbndout branch begin------------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = 	BINOUT_NBNDOUT_ID_DISCRETENODES,
							BINOUT_NBNDOUT_ID_DISCRETERIGIDBODIES,
							BINOUT_NBNDOUT_ID_PRESSURE,
							BINOUT_NBNDOUT_ID_VELOCITYNODES,
							BINOUT_NBNDOUT_ID_VELOCITYRIGIDBODIES,
							BINOUT_NBNDOUT_ID_ORIENTATIONRIGIDBODIES,
	*/
	BINOUT_NBNDOUT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_NBNDOUT_NUM_TIMESTEP,
	* parameters: idtype = 	BINOUT_NBNDOUT_ID_DISCRETENODES,
							BINOUT_NBNDOUT_ID_DISCRETERIGIDBODIES,
							BINOUT_NBNDOUT_ID_PRESSURE,
							BINOUT_NBNDOUT_ID_VELOCITYNODES,
							BINOUT_NBNDOUT_ID_VELOCITYRIGIDBODIES,
							BINOUT_NBNDOUT_ID_ORIENTATIONRIGIDBODIES,
	*/
	BINOUT_NBNDOUT_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = 	BINOUT_NBNDOUT_ID_DISCRETENODES,
							BINOUT_NBNDOUT_ID_DISCRETERIGIDBODIES,
							BINOUT_NBNDOUT_ID_PRESSURE,
							BINOUT_NBNDOUT_ID_VELOCITYNODES,
							BINOUT_NBNDOUT_ID_VELOCITYRIGIDBODIES,
							BINOUT_NBNDOUT_ID_ORIENTATIONRIGIDBODIES,
	*/
	BINOUT_NBNDOUT_NUM_ID,
	/**
	* conversion: usigned int
	* length    : BINOUT_NBNDOUT_NUM_ID
	* parameters: idtype = 	BINOUT_NBNDOUT_ID_DISCRETENODES,
							BINOUT_NBNDOUT_ID_DISCRETERIGIDBODIES,
							BINOUT_NBNDOUT_ID_PRESSURE,
							BINOUT_NBNDOUT_ID_VELOCITYNODES,
							BINOUT_NBNDOUT_ID_VELOCITYRIGIDBODIES,
							BINOUT_NBNDOUT_ID_ORIENTATIONRIGIDBODIES,
	*/
	BINOUT_NBNDOUT_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = 	BINOUT_NBNDOUT_ID_DISCRETENODES,
							BINOUT_NBNDOUT_ID_DISCRETERIGIDBODIES,
							BINOUT_NBNDOUT_ID_PRESSURE,
							BINOUT_NBNDOUT_ID_VELOCITYNODES,
							BINOUT_NBNDOUT_ID_VELOCITYRIGIDBODIES,
							BINOUT_NBNDOUT_ID_ORIENTATIONRIGIDBODIES,
	*/
	BINOUT_NBNDOUT_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_NBNDOUT_NUM_COMPONENT
	* parameters: idtype = 	BINOUT_NBNDOUT_ID_DISCRETENODES,
							BINOUT_NBNDOUT_ID_DISCRETERIGIDBODIES,
							BINOUT_NBNDOUT_ID_PRESSURE,
							BINOUT_NBNDOUT_ID_VELOCITYNODES,
							BINOUT_NBNDOUT_ID_VELOCITYRIGIDBODIES,
							BINOUT_NBNDOUT_ID_ORIENTATIONRIGIDBODIES,
	*/
	BINOUT_NBNDOUT_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_NBNDOUT_NUM_TIMESTEP
	* parameters: id, idtype = 	BINOUT_NBNDOUT_ID_DISCRETENODES,
							    BINOUT_NBNDOUT_ID_DISCRETERIGIDBODIES,
							    BINOUT_NBNDOUT_ID_PRESSURE,
							    BINOUT_NBNDOUT_ID_VELOCITYNODES,
							    BINOUT_NBNDOUT_ID_VELOCITYRIGIDBODIES,
							    BINOUT_NBNDOUT_ID_ORIENTATIONRIGIDBODIES,
	*/
	BINOUT_NBNDOUT_FORCE_X,
	BINOUT_NBNDOUT_FORCE_Y,
	BINOUT_NBNDOUT_FORCE_Z,
	BINOUT_NBNDOUT_ENERGY,
	BINOUT_NBNDOUT_MOMENT_X,
	BINOUT_NBNDOUT_MOMENT_Y,
	BINOUT_NBNDOUT_MOMENT_Z,
	/**
	* conversion: double
	* length    : BINOUT_NBNDOUT_NUM_TIMESTEP
	* parameters: idtype = 	BINOUT_NBNDOUT_ID_DISCRETENODES,
							BINOUT_NBNDOUT_ID_DISCRETERIGIDBODIES,
							BINOUT_NBNDOUT_ID_PRESSURE,
							BINOUT_NBNDOUT_ID_VELOCITYNODES,
							BINOUT_NBNDOUT_ID_VELOCITYRIGIDBODIES,
							BINOUT_NBNDOUT_ID_ORIENTATIONRIGIDBODIES,
	*/
	BINOUT_NBNDOUT_TOTAL_X,
	BINOUT_NBNDOUT_TOTAL_Y,
	BINOUT_NBNDOUT_TOTAL_Z,
	BINOUT_NBNDOUT_ETOTAL,
	/*----------------------------------------jntforc branch begin----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_JNTFORC_NUM_TYPES,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_JNTFORC_NUM_TYPES
	* parameters: ignore
	*/
	BINOUT_JNTFORC_TYPES,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype: BINOUT_JNTFORC_ID_JOINTS, BINOUT_JNTFORC_ID_STIFFNESS_TRANSLATIONAL,
	                      BINOUT_JNTFORC_ID_STIFFNESS_GENERALIZED
	*/
	BINOUT_JNTFORC_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_JNTFORC_NUM_ID
	* parameters: idtype: BINOUT_JNTFORC_ID_JOINTS, BINOUT_JNTFORC_ID_STIFFNESS_TRANSLATIONAL,
	                      BINOUT_JNTFORC_ID_STIFFNESS_GENERALIZED
	*/
	BINOUT_JNTFORC_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype: BINOUT_JNTFORC_ID_JOINTS, BINOUT_JNTFORC_ID_STIFFNESS_TRANSLATIONAL,
	                      BINOUT_JNTFORC_ID_STIFFNESS_GENERALIZED
	*/
	BINOUT_JNTFORC_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_NBNDOUT_NUM_TIMESTEP,
	* parameters: idtype: BINOUT_JNTFORC_ID_JOINTS, BINOUT_JNTFORC_ID_STIFFNESS_TRANSLATIONAL,
	                      BINOUT_JNTFORC_ID_STIFFNESS_GENERALIZED
	*/
	BINOUT_JNTFORC_X,
	/**
	* conversion: int
	* length    : 1,
	* parameters: idtype: BINOUT_JNTFORC_ID_JOINTS, BINOUT_JNTFORC_ID_STIFFNESS_TRANSLATIONAL,
	                      BINOUT_JNTFORC_ID_STIFFNESS_GENERALIZED
	*/
	BINOUT_JNTFORC_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_JNTFORC_NUM_COMPONENT,
	* parameters: idtype: BINOUT_JNTFORC_ID_JOINTS, BINOUT_JNTFORC_ID_STIFFNESS_TRANSLATIONAL,
	                      BINOUT_JNTFORC_ID_STIFFNESS_GENERALIZED
	*/
	BINOUT_JNTFORC_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_JNTFORC_NUM_TIMESTEP,
	* parameters: id, idtype: BINOUT_JNTFORC_ID_JOINTS                          
	*/
	BINOUT_JNTFORC_FORCE_X,
	BINOUT_JNTFORC_FORCE_Y,
	BINOUT_JNTFORC_FORCE_Z,
	BINOUT_JNTFORC_MOMENT_X,
	BINOUT_JNTFORC_MOMENT_Y,
	BINOUT_JNTFORC_MOMENT_Z,
	BINOUT_JNTFORC_RESULTANT_FORCE,
	BINOUT_JNTFORC_RESULTANT_MOMENT,
	BINOUT_JNTFORC_JOINT_ENERGY,
	/**
	* conversion: double
	* length    : BINOUT_JNTFORC_NUM_TIMESTEP,
	* parameters: id, idtype: BINOUT_JNTFORC_ID_STIFFNESS_TRANSLATIONAL
	*/
	BINOUT_JNTFORC_DISPLACEMENT_X,
	BINOUT_JNTFORC_DISPLACEMENT_Y,
	BINOUT_JNTFORC_DISPLACEMENT_Z,
	BINOUT_JNTFORC_DISPLACEMENT_X_DT,
	BINOUT_JNTFORC_DISPLACEMENT_Y_DT,
	BINOUT_JNTFORC_DISPLACEMENT_Z_DT,
	BINOUT_JNTFORC_FORCE_STIFFNESS_X,
	BINOUT_JNTFORC_FORCE_DAMPING_X,
	BINOUT_JNTFORC_FORCE_TOTAL_X,
	BINOUT_JNTFORC_FORCE_STIFFNESS_Y,
	BINOUT_JNTFORC_FORCE_DAMPING_Y,
	BINOUT_JNTFORC_FORCE_TOTAL_Y,
	BINOUT_JNTFORC_FORCE_STIFFNESS_Z,
	BINOUT_JNTFORC_FORCE_DAMPING_Z,
	BINOUT_JNTFORC_FORCE_TOTAL_Z,
	BINOUT_JNTFORC_TRANSLATION_JOINT_ENERGY,
	/**
	* conversion: double
	* length    : BINOUT_JNTFORC_NUM_TIMESTEP,
	* parameters: id, idtype: BINOUT_JNTFORC_ID_STIFFNESS_GENERALIZED
	*/
	BINOUT_JNTFORC_PHI_DEGREES,
	BINOUT_JNTFORC_PHI_DEGREES_DT,
	BINOUT_JNTFORC_THETA_DEGREES,
	BINOUT_JNTFORC_THETA_DEGREES_DT,
	BINOUT_JNTFORC_PSI_DEGREES,
	BINOUT_JNTFORC_PSI_DEGREES_DT,
	BINOUT_JNTFORC_PHI_MOMENT_STIFFNESS,
	BINOUT_JNTFORC_PHI_MOMENT_DAMPING,
	BINOUT_JNTFORC_PHI_MOMENT_TOTAL,
	BINOUT_JNTFORC_THETA_MOMENT_STIFFNESS,
	BINOUT_JNTFORC_THETA_MOMENT_DAMPING,
	BINOUT_JNTFORC_THETA_MOMENT_TOTAL,
	BINOUT_JNTFORC_PSI_MOMENT_STIFFNESS,
	BINOUT_JNTFORC_PSI_MOMENT_DAMPING,
	BINOUT_JNTFORC_PSI_MOMENT_TOTAL,
	BINOUT_JNTFORC_PHI_THETA_PSI_JOINT_ENERGY,

	BINOUT_JNTFORC_ALPHA_DEGREES,
	BINOUT_JNTFORC_ALPHA_DEGREES_DT,
	BINOUT_JNTFORC_GAMMA_DEGREES,
	BINOUT_JNTFORC_GAMMA_DEGREES_DT,
	BINOUT_JNTFORC_BETA_DEGREES,
	BINOUT_JNTFORC_BETA_DEGREES_DT,
	BINOUT_JNTFORC_ALPHA_MOMENT_STIFFNESS,
	BINOUT_JNTFORC_ALPHA_MOMENT_DAMPING,
	BINOUT_JNTFORC_ALPHA_MOMENT_TOTAL,
	BINOUT_JNTFORC_GAMMA_SCALE_FACTOR,
	BINOUT_JNTFORC_BETA_MOMENT_STIFFNESS,
	BINOUT_JNTFORC_BETA_MOMENT_DAMPING,
	BINOUT_JNTFORC_BETA_MOMENT_TOTAL,
	BINOUT_JNTFORC_ALPHA_GAMMA_BETA_JOINT_ENERGY,
	/*----------------------------------------nodout_ssd branch begin-------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODOUT_SSD_NUM_FREQUENCY,
	/**
	* conversion: double
	* length    : BINOUT_NODOUT_SSD_NUM_FREQUENCY
	* parameters: ignore
	*/
	BINOUT_NODOUT_SSD_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODOUT_SSD_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_NODOUT_SSD_NUM_ID
	* parameters: ignore
	*/
	BINOUT_NODOUT_SSD_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODOUT_SSD_NUM_MODE,
	/**
	* conversion: double
	* length    : BINOUT_NODOUT_SSD_NUM_MODE
	* parameters: ignore
	*/
	BINOUT_NODOUT_SSD_MODES,
	/**
	* conversion: int
	* length    : 1
	* parameters: datatype_option: BINOUT_DATATYPE_AMPLITUDE, BINOUT_DATATYPE_PHASEANGLE, BINOUT_DATATYPE_REAL,
	                               BINOUT_DATATYPE_IMAGINARY, BINOUT_DATATYPE_MODALCONTRIBUTION
	*/
	BINOUT_NODOUT_SSD_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_NODOUT_SSD_NUM_COMPONENT
	* parameters: datatype_option: BINOUT_DATATYPE_AMPLITUDE, BINOUT_DATATYPE_PHASEANGLE, BINOUT_DATATYPE_REAL,
	                               BINOUT_DATATYPE_IMAGINARY, BINOUT_DATATYPE_MODALCONTRIBUTION
	*/
	BINOUT_NODOUT_SSD_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_NODOUT_SSD_NUM_FREQUENCY
	* parameters: id, datatype_option: BINOUT_DATATYPE_ALPLITUDE, BINOUT_DATATYPE_PHASEANGLE,
									   BINOUT_DATATYPE_REAL,      BINOUT_DATATYPE_IMAGINARY
	*/
	BINOUT_NODOUT_SSD_TRANSLATIONAL_DISP_X,
	BINOUT_NODOUT_SSD_TRANSLATIONAL_VEL_X,
	BINOUT_NODOUT_SSD_TRANSLATIONAL_ACCL_X,
	BINOUT_NODOUT_SSD_TRANSLATIONAL_DISP_Y,
	BINOUT_NODOUT_SSD_TRANSLATIONAL_VEL_Y,
	BINOUT_NODOUT_SSD_TRANSLATIONAL_ACCL_Y,
	BINOUT_NODOUT_SSD_TRANSLATIONAL_DISP_Z,
	BINOUT_NODOUT_SSD_TRANSLATIONAL_VEL_Z,
	BINOUT_NODOUT_SSD_TRANSLATIONAL_ACCL_Z,
	BINOUT_NODOUT_SSD_ROTATIONAL_DISP_X,
	BINOUT_NODOUT_SSD_ROTATIONAL_VEL_X,
	BINOUT_NODOUT_SSD_ROTATIONAL_ACCL_X,
	BINOUT_NODOUT_SSD_ROTATIONAL_DISP_Y,
	BINOUT_NODOUT_SSD_ROTATIONAL_VEL_Y,
	BINOUT_NODOUT_SSD_ROTATIONAL_ACCL_Y,
	BINOUT_NODOUT_SSD_ROTATIONAL_DISP_Z,
	BINOUT_NODOUT_SSD_ROTATIONAL_VEL_Z,
	BINOUT_NODOUT_SSD_ROTATIONAL_ACCL_Z,
	/**
	* conversion: double
	* length    : BINOUT_NODOUT_SSD_NUM_FREQUENCY
	* parameters: id, freq_mode, datatype_option: BINOUT_DATATYPE_MODALCONTRIBUTATION
	*/
	BINOUT_NODOUT_SSD_MODALCONTRIBUTATION_ROTATIONAL_DISP_X,
	BINOUT_NODOUT_SSD_MODALCONTRIBUTATION_ROTATIONAL_DISP_Y,
	BINOUT_NODOUT_SSD_MODALCONTRIBUTATION_ROTATIONAL_DISP_Z,
	BINOUT_NODOUT_SSD_MODALCONTRIBUTATION_TRANSLATIONAL_DISP_X,
	BINOUT_NODOUT_SSD_MODALCONTRIBUTATION_TRANSLATIONAL_DISP_Y,
	BINOUT_NODOUT_SSD_MODALCONTRIBUTATION_TRANSLATIONAL_DISP_Z,

	/*----------------------------------------nodout_psd branch begin-------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODOUT_PSD_NUM_FREQUENCY,
	/**
	* conversion: double
	* length    : BINOUT_NODOUT_PSD_NUM_FREQUENCY
	* parameters: ignore
	*/
	BINOUT_NODOUT_PSD_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODOUT_PSD_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_NODOUT_PSD_NUM_ID
	* parameters: ignore
	*/
	BINOUT_NODOUT_PSD_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODOUT_PSD_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_NODOUT_PSD_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_NODOUT_PSD_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_NODOUT_PSD_NUM_FREQUENCY
	* parameters: id
	*/
	BINOUT_NODOUT_PSD_DISPLACEMENT_X,
	BINOUT_NODOUT_PSD_DISPLACEMENT_Y,
	BINOUT_NODOUT_PSD_DISPLACEMENT_Z,
	BINOUT_NODOUT_PSD_VELOCITY_X,
	BINOUT_NODOUT_PSD_VELOCITY_Y,
	BINOUT_NODOUT_PSD_VELOCITY_Z,
	BINOUT_NODOUT_PSD_ACCLERATION_X,
	BINOUT_NODOUT_PSD_ACCLERATION_Y,
	BINOUT_NODOUT_PSD_ACCLERATION_Z,

	/*---------------------------------------nodout_spcm branch begin-------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODOUT_SPCM_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_NODOUT_SPCM_NUM_ID
	* parameters: ignore
	*/
	BINOUT_NODOUT_SPCM_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODOUT_SPCM_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_NODOUT_SPCM_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_NODOUT_SPCM_COMPONENTS,
	/**
	* conversion: double
	* length    : 1
	* parameters: id
	*/
	BINOUT_NODOUT_SPCM_DISPLACEMENT_X,
	BINOUT_NODOUT_SPCM_VELOCITY_X,
	BINOUT_NODOUT_SPCM_ACCLERATION_X,
	BINOUT_NODOUT_SPCM_DISPLACEMENT_Y,
	BINOUT_NODOUT_SPCM_VELOCITY_Y,
	BINOUT_NODOUT_SPCM_ACCLERATION_Y,
	BINOUT_NODOUT_SPCM_DISPLACEMENT_Z,
	BINOUT_NODOUT_SPCM_VELOCITY_Z,
	BINOUT_NODOUT_SPCM_ACCLERATION_Z,
	/*-----------------------------------------rwforc branch begin------------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = 	BINOUT_RWFORC_ID_FORCES , BINOUT_RWFORC_ID_TRANSDUCER or BINOUT_RWFORC_ID_WALL,
	*/
	BINOUT_RWFORC_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_RWFORC_NUM_TIMESTEP,
	* parameters: idtype = 	BINOUT_RWFORC_ID_FORCES , BINOUT_RWFORC_ID_TRANSDUCER or BINOUT_RWFORC_ID_WALL,
	*/
	BINOUT_RWFORC_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = 	BINOUT_RWFORC_ID_FORCES , BINOUT_RWFORC_ID_TRANSDUCER or BINOUT_RWFORC_ID_WALL if BINOUT_RWFORC_ID_WALL param.wallid is needed,
	*/
	BINOUT_RWFORC_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_RWFORC_NUM_ID
	* parameters: idtype = 	BINOUT_RWFORC_ID_FORCES , BINOUT_RWFORC_ID_TRANSDUCER or BINOUT_RWFORC_ID_WALL if BINOUT_RWFORC_ID_WALL param.wallid is needed,
	*/
	BINOUT_RWFORC_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: id, idtype = BINOUT_RWFORC_ID_TRANSDUCER
	*/
	BINOUT_RWFORC_NUM_NODESET,
	/**
	* conversion: unsigned int
	* length    : BINOUT_RWFORC_NUM_NODESET
	* parameters: id, idtype = BINOUT_RWFORC_ID_TRANSDUCER
	*/
	BINOUT_RWFORC_NODESETS,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = 	BINOUT_RWFORC_ID_FORCES, BINOUT_RWFORC_ID_TRANSDUCER or BINOUT_RWFORC_ID_WALL if BINOUT_RWFORC_ID_WALL param.wallid is needed,,
	*/
	BINOUT_RWFORC_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_RWFORC_NUM_COMPONENT
	* parameters: idtype = 	BINOUT_RWFORC_ID_FORCES, BINOUT_RWFORC_ID_TRANSDUCER or BINOUT_RWFORC_ID_WALL if BINOUT_RWFORC_ID_WALL param.wallid is needed,,
	*/
	BINOUT_RWFORC_COMPONENTS,
	/**
    * conversion: double
    * length    : BINOUT_RWFORC_X
	* parameters: id, idtype = BINOUT_RWFORC_ID_FORCES
	*/
	BINOUT_RWFORC_NORMAL_FORCE,
	/**
	* conversion: double
	* length    : BINOUT_RWFORC_X
	* parameters: id, idtype = 	BINOUT_RWFORC_ID_FORCES, BINOUT_RWFORC_ID_TRANSDUCER or BINOUT_RWFORC_ID_WALL if BINOUT_RWFORC_ID_WALL param.wallid is needed,,
	*/
	BINOUT_RWFORC_FORCE_X,
	BINOUT_RWFORC_FORCE_Y,
	BINOUT_RWFORC_FORCE_Z,

	/*--------------------------------------nodfor_ssd branch begin---------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODFOR_SSD_NUM_FREQUENCY,
	/**
	* conversion: double
	* length    : BINOUT_NODFOR_SSD_NUM_FREQUENCY
	* parameters: ignore
	*/
	BINOUT_NODFOR_SSD_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODFOR_SSD_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_NODFOR_SSD_NUM_ID
	* parameters: ignore
	*/
	BINOUT_NODFOR_SSD_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODFOR_SSD_NUM_GROUPID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_NODFOR_SSD_NUM_GROUPID
	* parameters: ignore
	*/
	BINOUT_NODFOR_SSD_GROUP_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_NODFOR_SSD_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_NODFOR_SSD_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_NODFOR_SSD_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_NODFOR_SSD_NUM_FREQUENCY
	* parameters: id, idtype: BINOUT_NODFOR_SSD_ID_NODE,
	              datatype_option = BINOUT_DATATYPE_AMPLITUDE,  BINOUT_DATATYPE_PHASEANGLE,
								    BINOUT_DATATYPE_REAL,       BINOUT_DATATYPE_IMAGINARY,
	*/
	BINOUT_NODFOR_SSD_FORCE_X,
	BINOUT_NODFOR_SSD_FORCE_Y,
	BINOUT_NODFOR_SSD_FORCE_Z,
	/**
	* conversion: double
	* length    : BINOUT_NODFOR_SSD_NUM_FREQUENCY
	* parameters: id, idtype: BINOUT_NODFOR_SSD_ID_GROUP,
	              datatype_option = BINOUT_DATATYPE_AMPLITUDE,  BINOUT_DATATYPE_PHASEANGLE,
								    BINOUT_DATATYPE_REAL,       BINOUT_DATATYPE_IMAGINARY,
	*/
	BINOUT_NODFOR_SSD_TOTAL_X,
	BINOUT_NODFOR_SSD_TOTAL_Y,
	BINOUT_NODFOR_SSD_TOTAL_Z,

	/*-----------------------------------------eloutdet branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_ELOUTDET_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_ELOUTDET_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_ELOUTDET_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = 	BINOUT_ELOUTDET_ID_SOLID,BINOUT_ELOUTDET_ID_SHELL,BINOUT_ELOUTDET_ID_TSHELL or BINOUT_ELOUTDET_ID_NODAVG
	*/
	BINOUT_ELOUTDET_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_ELOUTDET_NUM_ID
	* parameters: idtype = 	BINOUT_ELOUTDET_ID_SOLID,BINOUT_ELOUTDET_ID_SHELL,BINOUT_ELOUTDET_ID_TSHELL or BINOUT_ELOUTDET_ID_NODAVG
	*/
	BINOUT_ELOUTDET_IDS,

	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = 	BINOUT_ELOUTDET_ID_SOLID,BINOUT_ELOUTDET_ID_SHELL,BINOUT_ELOUTDET_ID_TSHELL or BINOUT_ELOUTDET_ID_NODAVG
	*/
	BINOUT_ELOUTDET_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_ELOUTDET_NUM_COMPONENT
	* parameters: idtype = 	BINOUT_ELOUTDET_ID_SOLID,BINOUT_ELOUTDET_ID_SHELL,BINOUT_ELOUTDET_ID_TSHELL or BINOUT_ELOUTDET_ID_NODAVG
	*/
	BINOUT_ELOUTDET_COMPONENTS,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = 	BINOUT_ELOUTDET_ID_SOLID,BINOUT_ELOUTDET_ID_SHELL,BINOUT_ELOUTDET_ID_TSHELL or BINOUT_ELOUTDET_ID_NODAVG
	*/
	BINOUT_ELOUTDET_NUM_IPT,
	/**
	* conversion: unsigned int
	* length    : BINOUT_ELOUTDET_NUM_IPT
	* parameters: idtype = 	BINOUT_ELOUTDET_ID_SOLID,BINOUT_ELOUTDET_ID_SHELL,BINOUT_ELOUTDET_ID_TSHELL or BINOUT_ELOUTDET_ID_NODAVG
	*/
	BINOUT_ELOUTDET_IPTS,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = 	BINOUT_ELOUTDET_ID_SOLID,BINOUT_ELOUTDET_ID_SHELL,BINOUT_ELOUTDET_ID_TSHELL or BINOUT_ELOUTDET_ID_NODAVG
	*/
	BINOUT_ELOUTDET_NUM_NPL,
	/**
	* conversion: unsigned int
	* length    : BINOUT_ELOUTDET_NUM_NPL
	* parameters: idtype = 	BINOUT_ELOUTDET_ID_SOLID,BINOUT_ELOUTDET_ID_SHELL,BINOUT_ELOUTDET_ID_TSHELL or BINOUT_ELOUTDET_ID_NODAVG
	*/
	BINOUT_ELOUTDET_NPLS,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype = 	BINOUT_ELOUTDET_ID_SOLID,BINOUT_ELOUTDET_ID_SHELL,BINOUT_ELOUTDET_ID_TSHELL or BINOUT_ELOUTDET_ID_NODAVG
	*/
	BINOUT_ELOUTDET_NUM_NQT,
	/**
	* conversion: unsigned int
	* length    : BINOUT_ELOUTDET_NUM_NQT
	* parameters: idtype = 	BINOUT_ELOUTDET_ID_SOLID,BINOUT_ELOUTDET_ID_SHELL,BINOUT_ELOUTDET_ID_TSHELL or BINOUT_ELOUTDET_ID_NODAVG
	*/
	BINOUT_ELOUTDET_NQTS,
	/**
	* conversion: double
	* length    : BINOUT_ELOUTDET_NUM_TIMESTEP
	* parameters: datatype_option = BINOUT_DATATYPE_ELOUTDET_INTEGRATION_POINTS or BINOUT_DATATYPE_ELOUTDET_NODAL_POINTS,
	              idtype = BINOUT_ELOUTDET_ID_SOLID,BINOUT_ELOUTDET_ID_SHELL,BINOUT_ELOUTDET_ID_TSHELL or BINOUT_ELOUTDET_ID_NODAVG, 
	              id, ipt, npl, nqt
	*/
	BINOUT_ELOUTDET_EFFSG,
	BINOUT_ELOUTDET_EPS_XX,
	BINOUT_ELOUTDET_EPS_XY,
	BINOUT_ELOUTDET_EPS_YY,
	BINOUT_ELOUTDET_EPS_YZ,
	BINOUT_ELOUTDET_EPS_ZX,
	BINOUT_ELOUTDET_EPS_ZZ,
	BINOUT_ELOUTDET_SIG_XX,
	BINOUT_ELOUTDET_SIG_XY,
	BINOUT_ELOUTDET_SIG_YY,
	BINOUT_ELOUTDET_SIG_YZ,
	BINOUT_ELOUTDET_SIG_ZX,
	BINOUT_ELOUTDET_SIG_ZZ,
	BINOUT_ELOUTDET_YIELD,
	BINOUT_ELOUTDET_PLASTIC_STRAIN,
	/**
	* conversion: double
	* length    : BINOUT_ELOUTDET_NUM_TIMESTEP
	* parameters: idtype=BINOUT_ELOUTDET_ID_NODAVG, id
	*/
	BINOUT_ELOUTDET_LOWER_SIG_XX,
	BINOUT_ELOUTDET_LOWER_SIG_YY,
	BINOUT_ELOUTDET_LOWER_SIG_ZZ,
	BINOUT_ELOUTDET_LOWER_SIG_XY,
	BINOUT_ELOUTDET_LOWER_SIG_YZ,
	BINOUT_ELOUTDET_LOWER_SIG_ZX,
	BINOUT_ELOUTDET_LOWER_YIELD,
	BINOUT_ELOUTDET_UPPER_SIG_XX,
	BINOUT_ELOUTDET_UPPER_SIG_YY,
	BINOUT_ELOUTDET_UPPER_SIG_ZZ,
	BINOUT_ELOUTDET_UPPER_SIG_XY,
	BINOUT_ELOUTDET_UPPER_SIG_YZ,
	BINOUT_ELOUTDET_UPPER_SIG_ZX,
	BINOUT_ELOUTDET_UPPER_YIELD,
	BINOUT_ELOUTDET_LOWER_EPS_XX,
	BINOUT_ELOUTDET_LOWER_EPS_YY,
	BINOUT_ELOUTDET_LOWER_EPS_ZZ,
	BINOUT_ELOUTDET_LOWER_EPS_XY,
	BINOUT_ELOUTDET_LOWER_EPS_YZ,
	BINOUT_ELOUTDET_LOWER_EPS_ZX,
	BINOUT_ELOUTDET_UPPER_EPS_XX,
	BINOUT_ELOUTDET_UPPER_EPS_YY,
	BINOUT_ELOUTDET_UPPER_EPS_ZZ,
	BINOUT_ELOUTDET_UPPER_EPS_XY,
	BINOUT_ELOUTDET_UPPER_EPS_YZ,
	BINOUT_ELOUTDET_UPPER_EPS_ZX,
	/*---------------------------------------elout_ssd branch begin---------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_ELOUT_SSD_NUM_FREQUENCY,
	/**
	* conversion: double
	* length    : BINOUT_ELOUT_SSD_NUM_FREQUENCY
	* parameters: ignore
	*/
	BINOUT_ELOUT_SSD_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype: BINOUT_ELOUT_SSD_ID_BEAM,BINOUT_ELOUT_SSD_ID_SOLID,BINOUT_ELOUT_SSD_ID_TSHELL,
	                      BINOUT_ELOUT_ID_SHELL
	*/
	BINOUT_ELOUT_SSD_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_ELOUT_SSD_NUM_ID
	* parameters: idtype: BINOUT_ELOUT_SSD_ID_BEAM,BINOUT_ELOUT_SSD_ID_SOLID,BINOUT_ELOUT_SSD_ID_TSHELL,
	                      BINOUT_ELOUT_ID_SHELL
	*/
	BINOUT_ELOUT_SSD_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype: BINOUT_ELOUT_SSD_ID_BEAM,BINOUT_ELOUT_SSD_ID_SOLID,BINOUT_ELOUT_SSD_ID_TSHELL,
	                      BINOUT_ELOUT_ID_SHELL
	*/
	BINOUT_ELOUT_SSD_NUM_IPT,
	/**
	* conversion: unsigned int
	* length    : BINOUT_ELOUT_SSD_NUM_IPT
	* parameters: idtype: BINOUT_ELOUT_SSD_ID_BEAM,BINOUT_ELOUT_SSD_ID_SOLID,BINOUT_ELOUT_SSD_ID_TSHELL,
	                      BINOUT_ELOUT_ID_SHELL
	*/
	BINOUT_ELOUT_SSD_IPTS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_ELOUT_SSD_NUM_MODE,
	/**
	* conversion: double
	* length    : BINOUT_ELOUT_SSD_NUM_MODE
	* parameters: ignore
	*/
	BINOUT_ELOUT_SSD_MODES,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype: BINOUT_ELOUT_SSD_ID_BEAM,BINOUT_ELOUT_SSD_ID_SOLID,BINOUT_ELOUT_SSD_ID_TSHELL,
	                      BINOUT_ELOUT_ID_SHELL
				  datatype_option: BINOUT_DATATYPE_AMPLITUDE, BINOUT_DATATYPE_PHASEANGLE, BINOUT_DATATYPE_REAL,
				                   BINOUT_DATATYPE_IMAGINARY, BINOUT_DATATYPE_MODALCONTRIBUTION
	*/
	BINOUT_ELOUT_SSD_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_ELOUT_SSD_NUM_COMPONENT
	* parameters: idtype: BINOUT_ELOUT_SSD_ID_BEAM,BINOUT_ELOUT_SSD_ID_SOLID,BINOUT_ELOUT_SSD_ID_TSHELL,
	                      BINOUT_ELOUT_ID_SHELL
				  datatype_option: BINOUT_DATATYPE_AMPLITUDE, BINOUT_DATATYPE_PHASEANGLE, BINOUT_DATATYPE_REAL,
				                   BINOUT_DATATYPE_IMAGINARY, BINOUT_DATATYPE_MODALCONTRIBUTION
	*/
	BINOUT_ELOUT_SSD_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_ELOUT_SSD_NUM_FREQUENCY
	* parameters: id, ipt(shell,thickshell),
	              idtype: BINOUT_ELOUT_SSD_ID_SOLID,BINOUT_ELOUT_SSD_ID_TSHELL,BINOUT_ELOUT_ID_SHELL
				  datatype_option: BINOUT_DATATYPE_AMPLITUDE, BINOUT_DATATYPE_PHASEANGLE, BINOUT_DATATYPE_REAL,
				                   BINOUT_DATATYPE_IMAGINARY
	*/
	BINOUT_ELOUT_SSD_STRESS_XX,
	BINOUT_ELOUT_SSD_STRESS_YY,
	BINOUT_ELOUT_SSD_STRESS_ZZ,
	BINOUT_ELOUT_SSD_STRESS_XY,
	BINOUT_ELOUT_SSD_STRESS_YZ,
	BINOUT_ELOUT_SSD_STRESS_ZX,
	/**
	* conversion: double
	* length    : BINOUT_ELOUT_SSD_NUM_FREQUENCY
	* parameters: id, idtype: BINOUT_ELOUT_SSD_ID_SOLID
				  datatype_option: BINOUT_DATATYPE_AMPLITUDE, BINOUT_DATATYPE_PHASEANGLE, BINOUT_DATATYPE_REAL,
								   BINOUT_DATATYPE_IMAGINARY
	*/
	BINOUT_ELOUT_SSD_STRAIN_XX,
	BINOUT_ELOUT_SSD_STRAIN_YY,
	BINOUT_ELOUT_SSD_STRAIN_ZZ,
	BINOUT_ELOUT_SSD_STRAIN_XY,
	BINOUT_ELOUT_SSD_STRAIN_YZ,
	BINOUT_ELOUT_SSD_STRAIN_ZX,
	/**
	* conversion: double
	* length    : BINOUT_ELOUT_SSD_NUM_FREQUENCY
	* parameters: id, idtype: BINOUT_ELOUT_SSD_ID_SHELL, BINOUT_ELOUT_SSD_ID_TSHELL
			      datatype_option: BINOUT_DATATYPE_AMPLITUDE, BINOUT_DATATYPE_PHASEANGLE, BINOUT_DATATYPE_REAL,
				                   BINOUT_DATATYPE_IMAGINARY
	*/
	BINOUT_ELOUT_SSD_LOWER_STRAIN_XX,
	BINOUT_ELOUT_SSD_LOWER_STRAIN_YY,
	BINOUT_ELOUT_SSD_LOWER_STRAIN_ZZ,
	BINOUT_ELOUT_SSD_LOWER_STRAIN_XY,
	BINOUT_ELOUT_SSD_LOWER_STRAIN_YZ,
	BINOUT_ELOUT_SSD_LOWER_STRAIN_ZX,

	BINOUT_ELOUT_SSD_UPPER_STRAIN_XX,
	BINOUT_ELOUT_SSD_UPPER_STRAIN_YY,
	BINOUT_ELOUT_SSD_UPPER_STRAIN_ZZ,
	BINOUT_ELOUT_SSD_UPPER_STRAIN_XY,
	BINOUT_ELOUT_SSD_UPPER_STRAIN_YZ,
	BINOUT_ELOUT_SSD_UPPER_STRAIN_ZX,
	/**
	* conversion: double
	* length    : BINOUT_ELOUT_SSD_NUM_FREQUENCY
	* parameters: id, idtype: BINOUT_ELOUT_SSD_ID_BEAM
			      datatype_option: BINOUT_DATATYPE_AMPLITUDE, BINOUT_DATATYPE_PHASEANGLE, BINOUT_DATATYPE_REAL,
				                    BINOUT_DATATYPE_IMAGINARY
	*/
	BINOUT_ELOUT_SSD_AXIAL,
	BINOUT_ELOUT_SSD_SHEAR_S,
	BINOUT_ELOUT_SSD_SHEAR_T,
	BINOUT_ELOUT_SSD_MOMENT_S,
	BINOUT_ELOUT_SSD_MOMENT_T,
	BINOUT_ELOUT_SSD_TORSION,

	BINOUT_ELOUT_SSD_SIGMA_11,
	BINOUT_ELOUT_SSD_SIGMA_12,
	BINOUT_ELOUT_SSD_SIGMA_31,
	BINOUT_ELOUT_SSD_PLASTIC_EPS,
	BINOUT_ELOUT_SSD_AXIAL_STRAIN,
	/**
	* conversion: double
	* length    : BINOUT_ELOUT_SSD_NUM_FREQUENCY
	* parameters: id, ipt(shell, thickshell), freq_mode,
	              idtype: BINOUT_ELOUT_SSD_ID_SOLID, BINOUT_ELOUT_SSD_ID_TSHELL, BINOUT_ELOUT_SSD_ID_SHELL
			      datatype_option: BINOUT_DATATYPE_MODALCONTRIBUTION
	*/
	BINOUT_ELOUT_SSD_MODALCONTRIBUTION_STRESS_XX,
	BINOUT_ELOUT_SSD_MODALCONTRIBUTION_STRESS_YY,
	BINOUT_ELOUT_SSD_MODALCONTRIBUTION_STRESS_ZZ,
	BINOUT_ELOUT_SSD_MODALCONTRIBUTION_STRESS_XY,
	BINOUT_ELOUT_SSD_MODALCONTRIBUTION_STRESS_YZ,
	BINOUT_ELOUT_SSD_MODALCONTRIBUTION_STRESS_ZX,
	/**
	* conversion: double
	* length    : BINOUT_ELOUT_SSD_NUM_FREQUENCY
	* parameters: id, freq_mode,
	              idtype: BINOUT_ELOUT_SSD_ID_BEAM
			      datatype_option: BINOUT_DATATYPE_MODALCONTRIBUTION
	*/
	BINOUT_ELOUT_SSD_MODALCONTRIBUTION_AXIAL,
	BINOUT_ELOUT_SSD_MODALCONTRIBUTION_SHEAR_S,
	BINOUT_ELOUT_SSD_MODALCONTRIBUTION_SHEAR_T,
	BINOUT_ELOUT_SSD_MODALCONTRIBUTION_MOMENT_S,
	BINOUT_ELOUT_SSD_MODALCONTRIBUTION_MOMENT_T,
	BINOUT_ELOUT_SSD_MODALCONTRIBUTION_TORSION,

	/*--------------------------------------- elout_psd branch begin---------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_ELOUT_PSD_NUM_FREQUENCY,
	/**
	* conversion: double
	* length    : BINOUT_ELOUT_PSD_NUM_FREQUENCY
	* parameters: ignore
	*/
	BINOUT_ELOUT_PSD_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype: BINOUT_ELOUT_PSD_ID_BEAM, BINOUT_ELOUT_PSD_ID_SOLID, BINOUT_ELOUT_PSD_ID_TSHELL,
	                      BINOUT_ELOUT_PSD_ID_SHELL
	*/
	BINOUT_ELOUT_PSD_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_ELOUT_PSD_NUM_ID
	* parameters: idtype: BINOUT_ELOUT_PSD_ID_BEAM, BINOUT_ELOUT_PSD_ID_SOLID, BINOUT_ELOUT_PSD_ID_TSHELL,
	                      BINOUT_ELOUT_PSD_ID_SHELL
	*/
	BINOUT_ELOUT_PSD_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype: BINOUT_ELOUT_PSD_ID_BEAM, BINOUT_ELOUT_PSD_ID_SOLID, BINOUT_ELOUT_PSD_ID_TSHELL,
	                      BINOUT_ELOUT_PSD_ID_SHELL
	*/
	BINOUT_ELOUT_PSD_NUM_IPT,
	/**
	* conversion: unsigned int
	* length    : BINOUT_ELOUT_PSD_NUM_IPT
	* parameters: idtype: BINOUT_ELOUT_PSD_ID_BEAM, BINOUT_ELOUT_PSD_ID_SOLID, BINOUT_ELOUT_PSD_ID_TSHELL,
	                      BINOUT_ELOUT_PSD_ID_SHELL
	*/
	BINOUT_ELOUT_PSD_IPTS,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype: BINOUT_ELOUT_PSD_ID_BEAM, BINOUT_ELOUT_PSD_ID_SOLID, BINOUT_ELOUT_PSD_ID_TSHELL,
	                      BINOUT_ELOUT_PSD_ID_SHELL
	*/
	BINOUT_ELOUT_PSD_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_ELOUT_PSD_NUM_COMPONENT
	* parameters: idtype: BINOUT_ELOUT_PSD_ID_BEAM, BINOUT_ELOUT_PSD_ID_SOLID, BINOUT_ELOUT_PSD_ID_TSHELL,
	                      BINOUT_ELOUT_PSD_ID_SHELL
	*/
	BINOUT_ELOUT_PSD_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_ELOUT_PSD_NUM_FREQUENCY
	* parameters: id, ipt(shell,thickshell),
	              idtype: BINOUT_ELOUT_PSD_ID_SOLID, BINOUT_ELOUT_PSD_ID_TSHELL, BINOUT_ELOUT_PSD_ID_SHELL
	*/
	BINOUT_ELOUT_PSD_STRESS_XX,
	BINOUT_ELOUT_PSD_STRESS_YY,
	BINOUT_ELOUT_PSD_STRESS_ZZ,
	BINOUT_ELOUT_PSD_STRESS_XY,
	BINOUT_ELOUT_PSD_STRESS_YZ,
	BINOUT_ELOUT_PSD_STRESS_ZX,
	/**
	* conversion: double
	* length    : BINOUT_ELOUT_PSD_NUM_FREQUENCY
	* parameters: id, idtype: BINOUT_ELOUT_PSD_ID_SOLID
	*/
	BINOUT_ELOUT_PSD_STRAIN_XX,
	BINOUT_ELOUT_PSD_STRAIN_YY,
	BINOUT_ELOUT_PSD_STRAIN_ZZ,
	BINOUT_ELOUT_PSD_STRAIN_XY,
	BINOUT_ELOUT_PSD_STRAIN_YZ,
	BINOUT_ELOUT_PSD_STRAIN_ZX,
	/**
	* conversion: double
	* length    : BINOUT_ELOUT_PSD_NUM_FREQUENCY
	* parameters: id, idtype: BINOUT_ELOUT_PSD_ID_SHELL, BINOUT_ELOUT_PSD_ID_TSHELL
	*/
	BINOUT_ELOUT_PSD_LOWER_STRAIN_XX,
	BINOUT_ELOUT_PSD_LOWER_STRAIN_YY,
	BINOUT_ELOUT_PSD_LOWER_STRAIN_ZZ,
	BINOUT_ELOUT_PSD_LOWER_STRAIN_XY,
	BINOUT_ELOUT_PSD_LOWER_STRAIN_YZ,
	BINOUT_ELOUT_PSD_LOWER_STRAIN_ZX,

	BINOUT_ELOUT_PSD_UPPER_STRAIN_XX,
	BINOUT_ELOUT_PSD_UPPER_STRAIN_YY,
	BINOUT_ELOUT_PSD_UPPER_STRAIN_ZZ,
	BINOUT_ELOUT_PSD_UPPER_STRAIN_XY,
	BINOUT_ELOUT_PSD_UPPER_STRAIN_YZ,
	BINOUT_ELOUT_PSD_UPPER_STRAIN_ZX,
	/**
	* conversion: double
	* length    : BINOUT_ELOUT_PSD_NUM_FREQUENCY
	* parameters: id, idtype: BINOUT_ELOUT_PSD_ID_BEAM
	*/
	BINOUT_ELOUT_PSD_AXIAL,
	BINOUT_ELOUT_PSD_SHEAR_S,
	BINOUT_ELOUT_PSD_SHEAR_T,
	BINOUT_ELOUT_PSD_MOMENT_S,
	BINOUT_ELOUT_PSD_MOMENT_T,
	BINOUT_ELOUT_PSD_TORSION,

	BINOUT_ELOUT_PSD_SIGMA_11,
	BINOUT_ELOUT_PSD_SIGMA_12,
	BINOUT_ELOUT_PSD_SIGMA_31,
	BINOUT_ELOUT_PSD_PLASTIC_EPS,
	BINOUT_ELOUT_PSD_AXIAL_STRAIN,

	/*---------------------------------------elout_spcm branch begin---------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype: BINOUT_ELOUT_SPCM_ID_BEAM, BINOUT_ELOUT_SPCM_ID_SOLID, BINOUT_ELOUT_SPCM_ID_TSHELL,
	                      BINOUT_ELOUT_SPCM_ID_SHELL
	*/
	BINOUT_ELOUT_SPCM_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_ELOUT_SPCM_NUM_ID
	* parameters: idtype: BINOUT_ELOUT_SPCM_ID_BEAM, BINOUT_ELOUT_SPCM_ID_SOLID, BINOUT_ELOUT_SPCM_ID_TSHELL,
	                      BINOUT_ELOUT_SPCM_ID_SHELL
	*/
	BINOUT_ELOUT_SPCM_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype: BINOUT_ELOUT_SPCM_ID_BEAM, BINOUT_ELOUT_SPCM_ID_SOLID, BINOUT_ELOUT_SPCM_ID_TSHELL,
	                      BINOUT_ELOUT_SPCM_ID_SHELL
	*/
	BINOUT_ELOUT_SPCM_NUM_IPT,
	/**
	* conversion: int
	* length    : BINOUT_ELOUT_SPCM_NUM_IPT
	* parameters: idtype: BINOUT_ELOUT_SPCM_ID_BEAM, BINOUT_ELOUT_SPCM_ID_SOLID, BINOUT_ELOUT_SPCM_ID_TSHELL,
	                      BINOUT_ELOUT_SPCM_ID_SHELL
	*/
	BINOUT_ELOUT_SPCM_IPTS,
	/**
	* conversion: int
	* length    : 1
	* parameters: idtype: BINOUT_ELOUT_SPCM_ID_BEAM, BINOUT_ELOUT_SPCM_ID_SOLID, BINOUT_ELOUT_SPCM_ID_TSHELL,
	                      BINOUT_ELOUT_SPCM_ID_SHELL
	*/
	BINOUT_ELOUT_SPCM_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_ELOUT_SPCM_NUM_COMPONENT
	* parameters: idtype: BINOUT_ELOUT_SPCM_ID_BEAM, BINOUT_ELOUT_SPCM_ID_SOLID, BINOUT_ELOUT_SPCM_ID_TSHELL,
	                      BINOUT_ELOUT_SPCM_ID_SHELL
	*/
	BINOUT_ELOUT_SPCM_COMPONENTS,
	/**
	* conversion: double
	* length    : 1
	* parameters: id, ipt(shell,thickshell),
	              idtype: BINOUT_ELOUT_SPCM_ID_SOLID, BINOUT_ELOUT_SPCM_ID_SHELL, BINOUT_ELOUT_SPCM_ID_TSHELL
	*/
	BINOUT_ELOUT_SPCM_STRESS_XX,
	BINOUT_ELOUT_SPCM_STRESS_YY,
	BINOUT_ELOUT_SPCM_STRESS_ZZ,
	BINOUT_ELOUT_SPCM_STRESS_XY,
	BINOUT_ELOUT_SPCM_STRESS_YZ,
	BINOUT_ELOUT_SPCM_STRESS_ZX,
	/**
	* conversion: double
	* length    : 1
	* parameters: id, idtype: BINOUT_ELOUT_SPCM_ID_BEAM
	*/
	BINOUT_ELOUT_SPCM_AXIAL,
	BINOUT_ELOUT_SPCM_SHEAR_S,
	BINOUT_ELOUT_SPCM_SHEAR_T,
	BINOUT_ELOUT_SPCM_MOMENT_S,
	BINOUT_ELOUT_SPCM_MOMENT_T,
	BINOUT_ELOUT_SPCM_TORSION,
	/**
	* conversion: double
	* length    : 1
	* parameters: id, ipt(beam), idtype: BINOUT_ELOUT_SPCM_ID_BEAM
	*/
	BINOUT_ELOUT_SPCM_SIGMA_11,
	BINOUT_ELOUT_SPCM_SIGMA_12,
	BINOUT_ELOUT_SPCM_SIGMA_31,
	BINOUT_ELOUT_SPCM_PLASTIC_EPS,
	BINOUT_ELOUT_SPCM_AXIAL_STRAIN,

	/*-----------------------------------------rbdout branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_RBDOUT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_RBDOUT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_RBDOUT_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_RBDOUT_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_RBDOUT_NUM_ID
	* parameters: ignore
	*/
	BINOUT_RBDOUT_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_RBDOUT_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_RBDOUT_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_RBDOUT_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_RBDOUT_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_RBDOUT_DIRCOS_11,
	BINOUT_RBDOUT_DIRCOS_12,
	BINOUT_RBDOUT_DIRCOS_13,
	BINOUT_RBDOUT_DIRCOS_21,
	BINOUT_RBDOUT_DIRCOS_22,
	BINOUT_RBDOUT_DIRCOS_23,
	BINOUT_RBDOUT_DIRCOS_31,
	BINOUT_RBDOUT_DIRCOS_32,
	BINOUT_RBDOUT_DIRCOS_33,
	BINOUT_RBDOUT_GLOBAL_AX,
	BINOUT_RBDOUT_GLOBAL_AY,
	BINOUT_RBDOUT_GLOBAL_AZ,
	BINOUT_RBDOUT_GLOBAL_DX,
	BINOUT_RBDOUT_GLOBAL_DY,
	BINOUT_RBDOUT_GLOBAL_DZ,
	BINOUT_RBDOUT_GLOBAL_RAX,
	BINOUT_RBDOUT_GLOBAL_RAY,
	BINOUT_RBDOUT_GLOBAL_RAZ,
	BINOUT_RBDOUT_GLOBAL_RDX,
	BINOUT_RBDOUT_GLOBAL_RDY,
	BINOUT_RBDOUT_GLOBAL_RDZ,
	BINOUT_RBDOUT_GLOBAL_RVX,
	BINOUT_RBDOUT_GLOBAL_RVY,
	BINOUT_RBDOUT_GLOBAL_RVZ,
	BINOUT_RBDOUT_GLOBAL_VX,
	BINOUT_RBDOUT_GLOBAL_VY,
	BINOUT_RBDOUT_GLOBAL_VZ,
	BINOUT_RBDOUT_GLOBAL_X,
	BINOUT_RBDOUT_GLOBAL_Y,
	BINOUT_RBDOUT_GLOBAL_Z,
	BINOUT_RBDOUT_LOCAL_AX,
	BINOUT_RBDOUT_LOCAL_AY,
	BINOUT_RBDOUT_LOCAL_AZ,
	BINOUT_RBDOUT_LOCAL_DX,
	BINOUT_RBDOUT_LOCAL_DY,
	BINOUT_RBDOUT_LOCAL_DZ,
	BINOUT_RBDOUT_LOCAL_RAX,
	BINOUT_RBDOUT_LOCAL_RAY,
	BINOUT_RBDOUT_LOCAL_RAZ,
	BINOUT_RBDOUT_LOCAL_RDX,
	BINOUT_RBDOUT_LOCAL_RDY,
	BINOUT_RBDOUT_LOCAL_RDZ,
	BINOUT_RBDOUT_LOCAL_RVX,
	BINOUT_RBDOUT_LOCAL_RVY,
	BINOUT_RBDOUT_LOCAL_RVZ,
	BINOUT_RBDOUT_LOCAL_VX,
	BINOUT_RBDOUT_LOCAL_VY,
	BINOUT_RBDOUT_LOCAL_VZ,
	/*-----------------------------------------sleout branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SLEOUT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_SLEOUT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_SLEOUT_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SLEOUT_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_SLEOUT_NUM_ID
	* parameters: ignore
	*/
	BINOUT_SLEOUT_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SLEOUT_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_SLEOUT_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_SLEOUT_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_SLEOUT_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_SLEOUT_FRICTION_ENERGY,
	BINOUT_SLEOUT_MASTER,
	BINOUT_SLEOUT_SLAVE,
	BINOUT_SLEOUT_SLAVEMASTER,
	/**
	* conversion: double
	* length    : BINOUT_SLEOUT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_SLEOUT_TOTAL_ENERGY,
	BINOUT_SLEOUT_TOTAL_FRICTION,
	BINOUT_SLEOUT_TOTAL_MASTER,
	BINOUT_SLEOUT_TOTAL_SLAVE,
	/*-----------------------------------------spcforc branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SPCFORC_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_SPCFORC_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_SPCFORC_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SPCFORC_NUM_FORCEID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_SPCFORC_NUM_FORCEID
	* parameters: ignore
	*/
	BINOUT_SPCFORC_FORCE_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SPCFORC_NUM_FORCESETID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_SPCFORC_NUM_FORCESETID
	* parameters: ignore
	*/
	BINOUT_SPCFORC_FORCESET_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SPCFORC_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_SPCFORC_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_SPCFORC_COMPONENTS,

	/**
	* conversion: double
	* length    : BINOUT_SPCFORC_NUM_TIMESTEP
	* parameters: id = force_id
	*/
	BINOUT_SPCFORC_FORCE_X,
	BINOUT_SPCFORC_FORCE_Y,
	BINOUT_SPCFORC_FORCE_Z,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SPCFORC_NUM_MOMENTID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_SPCFORC_NUM_MOMENTID
	* parameters: ignore
	*/
	BINOUT_SPCFORC_MOMENT_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SPCFORC_NUM_MOMENTSETID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_SPCFORC_NUM_MOMENTSETID
	* parameters: ignore
	*/
	BINOUT_SPCFORC_MOMENTSET_IDS,
	/**
	* conversion: double
	* length    : BINOUT_SPCFORC_NUM_TIMESTEP
	* parameters: id = moment_id
	*/
	BINOUT_SPCFORC_MOMENT_X,
	BINOUT_SPCFORC_MOMENT_Y,
	BINOUT_SPCFORC_MOMENT_Z,
	/**
	* conversion: double
	* length    : BINOUT_SPCFORC_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_SPCFORC_RESULTANT_X,
	BINOUT_SPCFORC_RESULTANT_Y,
	BINOUT_SPCFORC_RESULTANT_Z,
	/*-----------------------------------------swforc branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SWFORC_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_SWFORC_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_SWFORC_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SWFORC_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_SWFORC_NUM_ID
	* parameters: ignore
	*/
	BINOUT_SWFORC_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_SWFORC_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_SWFORC_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_SWFORC_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_SWFORC_NUM_TIMESTEP
	* parameters: id,  idtype: BINOUT_SWFORC_ID_CONSTRAINT, BINOUT_SWFORC_ID_WELD, BINOUT_SWFORC_ID_BEAM, BINOUT_SWFORC_ID_SOLID,
	                           BINOUT_SWFORC_ID_NONNODAL_CONSTRAINT, BINOUT_SWFORC_ID_SOLID_ASSEMBLY
	*/
	BINOUT_SWFORC_AXIAL,
	BINOUT_SWFORC_FAILURE,
	BINOUT_SWFORC_LENGTH,
	BINOUT_SWFORC_RESULTANT_MOMENT,
	BINOUT_SWFORC_SHEAR,
	BINOUT_SWFORC_TORSION,
	/*-----------------------------------------curvout branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_CURVOUT_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_CURVOUT_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_CURVOUT_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_CURVOUT_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_CURVOUT_NUM_ID
	* parameters: ignore
	*/
	BINOUT_CURVOUT_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_CURVOUT_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_CURVOUT_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_CURVOUT_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_CURVOUT_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_CURVOUT_VALUES,
	/*-----------------------------------------dbsensor branch begin-----------------------------------------*/
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DBSENSOR_NUM_TIMESTEP,
	/**
	* conversion: double
	* length    : BINOUT_DBSENSOR_NUM_TIMESTEP
	* parameters: ignore
	*/
	BINOUT_DBSENSOR_X,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DBSENSOR_NUM_ID,
	/**
	* conversion: unsigned int
	* length    : BINOUT_DBSENSOR_NUM_ID
	* parameters: ignore
	*/
	BINOUT_DBSENSOR_IDS,
	/**
	* conversion: int
	* length    : 1
	* parameters: ignore
	*/
	BINOUT_DBSENSOR_NUM_COMPONENT,
	/**
	* conversion: BinoutStringArray
	* length    : BINOUT_DBSENSOR_NUM_COMPONENT
	* parameters: ignore
	*/
	BINOUT_DBSENSOR_COMPONENTS,
	/**
	* conversion: double
	* length    : BINOUT_DBSENSOR_NUM_TIMESTEP
	* parameters: id
	*/
	BINOUT_DBSENSOR_PRESSURE,
	BINOUT_DBSENSOR_SOLID_ID,
	BINOUT_DBSENSOR_TEMPERATURE,
	BINOUT_DBSENSOR_POSITION_X,
	BINOUT_DBSENSOR_POSITION_Y,
	BINOUT_DBSENSOR_POSITION_Z,
};
#endif

struct BINOUT_Parameter
{
	/**
	* the entity id, default is 0
	*/
	int id;
	/**
	* the number through thickness integration point,  default is 1
	*/
	int ipt;
	/**
   * the node id  of element, for the eloutdet branch only,  default is 0
   */
	int nqt;
	/**
	*  the number of  in-plane integration point,  default is 1
	*/
	int npl;
	/**
	* the nth order mode,  default is 1
	*/
	int freq_mode;
	/**
	* the contact id for ncforc, default is 0
	*/
	int cid;
	/**
	* the nodeset id for rwforc, and default is 0
	*/
	int nodeset;
	/**
	 * the number of history variable, and default is 1
	*/
	int ihv;
	/**
	* the wallid id for rwforc, and default is 1
	*/
	int wallid;
	/**
	* the type of entity id
	*/
	BINOUT_IdType idtype;
	/**
	* the option  for BINOUT_DataType
	*/
	BINOUT_DataTypeOption datatype_option;

	BINOUT_Parameter() : id(0), ipt(1), nqt(0), npl(1), freq_mode(1), cid(0), nodeset(0),ihv(1), wallid(1), idtype(BINOUT_IDTYPE_NONE), datatype_option(BINOUT_DATATYPE_GENERAL)
	{
	}
};
class BinoutStringArrayImp;
class  READERAPI BinoutStringArray
{
public:
	BinoutStringArray();
	~BinoutStringArray();
public:
	BinoutStringArrayImp* _imp;
public:
	std::size_t size() const;
	const char* operator[](std::size_t i) const;
};

class BinoutReaderImp;
class READERAPI BinoutReader
{
	// recommended API
public:
	bool GetData(BINOUT_DataType type, char* value, const BINOUT_Parameter& param = BINOUT_Parameter());

public:
	static bool IsValid(const char* filename);
	static bool Write(const char* filename, const std::vector<double>& x_array, const std::vector<double>& y_array);

	// deprecated API
public:
	bool SetBranch(const char* branch);
	bool GetBranch(BinoutStringArray& branches);
	bool SetId(const char* id);
	bool SetId(unsigned int id);
	bool SetId(unsigned int id, bool master);
	bool SetIdIndex(unsigned int idindex);
	bool GetId(std::vector<unsigned int>& ids);
	bool GetId(BinoutStringArray& ids);
	bool SetComponent(const char* comp);
	bool GetComponent(BinoutStringArray& comps);
	bool GetXArray(std::vector<double>& x_array);
	bool GetYArray(std::vector<double>& y_array);
	void Close();

	bool SetIpt(unsigned int ipt);
	bool GetIpt(std::vector<unsigned int>& ipts);

	bool SetNqt(unsigned int nqt);
	bool GetNqt(std::vector<unsigned int>& nqts);

	bool SetNpl(unsigned int npl);
	bool GetNpl(std::vector<unsigned int>& npls);

	bool SetDataSub(unsigned int type);
	bool GetDataSub(std::vector<unsigned int>& types);

	bool SetFrequencyMode(unsigned int mode);
	bool GetFrequencyMode(std::vector<double>& modes);

public:
	BinoutReader(const char* filename);
	~BinoutReader();

private:
	//BinoutReader(const BinoutReader&);
	//BinoutReader& operator=(const BinoutReader&);
	BinoutReaderImp* _imp;
};

READERAPI const char* GetLSReaderVersion();

#endif // ! __BINOUTREADER__H

