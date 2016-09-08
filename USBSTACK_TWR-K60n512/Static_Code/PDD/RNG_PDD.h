/*
  PDD layer implementation for peripheral type RNG
  (C) 2013 Freescale, Inc. All rights reserved.

  This file is static and it is generated from API-Factory
*/

#if !defined(RNG_PDD_H_)
#define RNG_PDD_H_

/* ----------------------------------------------------------------------------
   -- Test if supported MCU is active
   ---------------------------------------------------------------------------- */

#if !defined(MCU_ACTIVE)
  // No MCU is active
  #error RNG PDD library: No derivative is active. Place proper #include with PDD memory map before including PDD library.
#elif \
      !defined(MCU_MK52DZ10) /* RNG */ && \
      !defined(MCU_MK53DZ10) /* RNG */ && \
      !defined(MCU_MK60DZ10) /* RNG */ && \
      !defined(MCU_MK60N512VMD100) /* RNG */
  // Unsupported MCU is active
  #error RNG PDD library: Unsupported derivative is active.
#endif

#include "PDD_Types.h"

/* ----------------------------------------------------------------------------
   -- Method symbol definitions
   ---------------------------------------------------------------------------- */

/* Auto-reseed constants */
#define RNG_PDD_RESEED_DISABLE 0U                /**< No automatic reseed. */
#define RNG_PDD_RESEED_ENABLE  RNG_CR_AR_MASK    /**< Automatic reseed enabled. */

/* FIFO Underflow response mode constants */
#define RNG_PDD_RET_ZERO         0U              /**< Return zero. */
#define RNG_PDD_GEN_BUS_ERROR    0x2U            /**< Generate bus error. */
#define RNG_PDD_GEN_INT_RET_ZERO 0x3U            /**< Generate interrupt and return zero. */

/* Status of RNG */
#define RNG_PDD_STATUS_ERROR          0xFFFFU    /**< Error occured. */
#define RNG_PDD_STATUS_NEW_SEED_DONE  0x40U      /**< New seed done. */
#define RNG_PDD_STATUS_SEED_DONE      0x20U      /**< Seed done. */
#define RNG_PDD_STATUS_SELF_TEST_DONE 0x10U      /**< Self-test done. */
#define RNG_PDD_STATUS_RESEED_NEEDED  0x8U       /**< Reseed needed. */
#define RNG_PDD_STATUS_SLEEP          0x4U       /**< RNG in sleep mode. */
#define RNG_PDD_STATUS_BUSY           0x2U       /**< RNG is busy. */

/* Extended error mask for status register */
#define RNG_PDD_SELF_TETS_RESEED_ERROR  0x200000U /**< Reseed error. */
#define RNG_PDD_SELF_TEST_PRNG_ERROR    0x400000U /**< PRNG error. */
#define RNG_PDD_SELF_TEST_TRNG_ERROR    0x800000U /**< TRNG error. */
#define RNG_PDD_MONOBIT_TEST_ERROR      0x1000000U /**< Monobit test error. */
#define RNG_PDD_LENGTH_1_RUN_TEST_ERROR 0x2000000U /**< Length 1 test error. */
#define RNG_PDD_LENGTH_2_RUN_TEST_ERROR 0x4000000U /**< Length 2 test error. */
#define RNG_PDD_LENGTH_3_RUN_TEST_ERROR 0x8000000U /**< Length 3 test error. */
#define RNG_PDD_LENGTH_4_RUN_TEST_ERROR 0x10000000U /**< Length 4 test error. */
#define RNG_PDD_LENGTH_5_RUN_TEST_ERROR 0x20000000U /**< Length 5 test error. */
#define RNG_PDD_LENGTH_6_RUN_TEST_ERROR 0x40000000U /**< Length 6 test error. */
#define RNG_PDD_LONG_RUN_TEST_ERROR     0x80000000U /**< Long run test error. */

/* Error mask for error status register */
#define RNG_PDD_LFSR_ERROR           0x1U        /**< LFSR error. */
#define RNG_PDD_OSCILLATOR_ERROR     0x2U        /**< Oscillator error. */
#define RNG_PDD_SELF_TEST_ERROR      0x4U        /**< Self-test error. */
#define RNG_PDD_FIFO_UNDERFLOW_ERROR 0x8U        /**< FIFO underflow error. */


/* ----------------------------------------------------------------------------
   -- EnableInterrupts
   ---------------------------------------------------------------------------- */

/**
 * @brief Enables error and done interrupt.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: RNG_CR.
 * @par Example:
 *      @code
 *      RNG_PDD_EnableInterrupts(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_EnableInterrupts(PeripheralBase) ( \
    (RNG_CR_REG(PeripheralBase) &= \
     (uint32_t)(~(uint32_t)RNG_CR_MASKERR_MASK)), \
    (RNG_CR_REG(PeripheralBase) &= \
     (uint32_t)(~(uint32_t)RNG_CR_MASKDONE_MASK)) \
  )

/* ----------------------------------------------------------------------------
   -- DisableInterrupts
   ---------------------------------------------------------------------------- */

/**
 * @brief Disables error and done interrupt.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: RNG_CR.
 * @par Example:
 *      @code
 *      RNG_PDD_DisableInterrupts(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_DisableInterrupts(PeripheralBase) ( \
    (RNG_CR_REG(PeripheralBase) |= \
     RNG_CR_MASKERR_MASK), \
    (RNG_CR_REG(PeripheralBase) |= \
     RNG_CR_MASKDONE_MASK) \
  )

/* ----------------------------------------------------------------------------
   -- GetVersion
   ---------------------------------------------------------------------------- */

/**
 * @brief Returns version of RNG module.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 16-bit value.
 * @remarks The macro accesses the following registers: RNG_VER.
 * @par Example:
 *      @code
 *      uint16_t result = RNG_PDD_GetVersion(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_GetVersion(PeripheralBase) ( \
    (uint16_t)(RNG_VER_REG(PeripheralBase) & 0xFFFFU) \
  )

/* ----------------------------------------------------------------------------
   -- ErrorCondition
   ---------------------------------------------------------------------------- */

/**
 * @brief Returns 1 if there is error in RNG module.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 1-bit value. The value is cast to "uint8_t".
 * @remarks The macro accesses the following registers: RNG_SR.
 * @par Example:
 *      @code
 *      uint8_t result = RNG_PDD_ErrorCondition(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_ErrorCondition(PeripheralBase) ( \
    (uint8_t)((uint32_t)(RNG_SR_REG(PeripheralBase) & RNG_SR_ERR_MASK) >> RNG_SR_ERR_SHIFT) \
  )

/* ----------------------------------------------------------------------------
   -- Busy
   ---------------------------------------------------------------------------- */

/**
 * @brief Returns 1 if RNG is busy (generating seed, in self test mode...).
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 1-bit value. The value is cast to "uint8_t".
 * @remarks The macro accesses the following registers: RNG_SR.
 * @par Example:
 *      @code
 *      uint8_t result = RNG_PDD_Busy(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_Busy(PeripheralBase) ( \
    (uint8_t)((uint32_t)(RNG_SR_REG(PeripheralBase) & RNG_SR_BUSY_MASK) >> RNG_SR_BUSY_SHIFT) \
  )

/* ----------------------------------------------------------------------------
   -- SeedGenerated
   ---------------------------------------------------------------------------- */

/**
 * @brief Returns 1 if the seed was generated since last reset.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 1-bit value. The value is cast to "uint8_t".
 * @remarks The macro accesses the following registers: RNG_SR.
 * @par Example:
 *      @code
 *      uint8_t result = RNG_PDD_SeedGenerated(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_SeedGenerated(PeripheralBase) ( \
    (uint8_t)((uint32_t)(RNG_SR_REG(PeripheralBase) & RNG_SR_SDN_MASK) >> RNG_SR_SDN_SHIFT) \
  )

/* ----------------------------------------------------------------------------
   -- SoftReset
   ---------------------------------------------------------------------------- */

/**
 * @brief Performs a software reset of the RNGB.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: RNG_CMD.
 * @par Example:
 *      @code
 *      RNG_PDD_SoftReset(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_SoftReset(PeripheralBase) ( \
    RNG_CMD_REG(PeripheralBase) |= \
     RNG_CMD_SR_MASK \
  )

/* ----------------------------------------------------------------------------
   -- ClearErrorAndInterrupts
   ---------------------------------------------------------------------------- */

/**
 * @brief Clears the errors in the RNG_ESR register and the RNGB interrupt.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: RNG_CMD.
 * @par Example:
 *      @code
 *      RNG_PDD_ClearErrorAndInterrupts(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_ClearErrorAndInterrupts(PeripheralBase) ( \
    (RNG_CMD_REG(PeripheralBase) |= \
     RNG_CMD_CE_MASK), \
    (RNG_CMD_REG(PeripheralBase) |= \
     RNG_CMD_CI_MASK) \
  )

/* ----------------------------------------------------------------------------
   -- ClearError
   ---------------------------------------------------------------------------- */

/**
 * @brief Clears the errors in the RNG_ESR register.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: RNG_CMD.
 * @par Example:
 *      @code
 *      RNG_PDD_ClearError(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_ClearError(PeripheralBase) ( \
    RNG_CMD_REG(PeripheralBase) |= \
     RNG_CMD_CE_MASK \
  )

/* ----------------------------------------------------------------------------
   -- ClearInterrupt
   ---------------------------------------------------------------------------- */

/**
 * @brief Clears the RNGB interrupt if an error is not present.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: RNG_CMD.
 * @par Example:
 *      @code
 *      RNG_PDD_ClearInterrupt(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_ClearInterrupt(PeripheralBase) ( \
    RNG_CMD_REG(PeripheralBase) |= \
     RNG_CMD_CI_MASK \
  )

/* ----------------------------------------------------------------------------
   -- GenerateSeed
   ---------------------------------------------------------------------------- */

/**
 * @brief Initiates the seed generation process.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: RNG_CMD.
 * @par Example:
 *      @code
 *      RNG_PDD_GenerateSeed(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_GenerateSeed(PeripheralBase) ( \
    RNG_CMD_REG(PeripheralBase) |= \
     RNG_CMD_GS_MASK \
  )

/* ----------------------------------------------------------------------------
   -- SelfTest
   ---------------------------------------------------------------------------- */

/**
 * @brief Initiates a self test of the RNGB's internal logic.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: RNG_CMD.
 * @par Example:
 *      @code
 *      RNG_PDD_SelfTest(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_SelfTest(PeripheralBase) ( \
    RNG_CMD_REG(PeripheralBase) |= \
     RNG_CMD_ST_MASK \
  )

/* ----------------------------------------------------------------------------
   -- AutoReseed
   ---------------------------------------------------------------------------- */

/**
 * @brief Configures automatic reseeding.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Reseed Determines auto-reseed function. Use constants from group
 *        "Auto-reseed constants". This parameter is 32 bits wide.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: RNG_CR.
 * @par Example:
 *      @code
 *      RNG_PDD_AutoReseed(<peripheral>_BASE_PTR, RNG_PDD_RESEED_DISABLE);
 *      @endcode
 */
#define RNG_PDD_AutoReseed(PeripheralBase, Reseed) ( \
    RNG_CR_REG(PeripheralBase) = \
     (uint32_t)(( \
      (uint32_t)(RNG_CR_REG(PeripheralBase) & (uint32_t)(~(uint32_t)RNG_CR_AR_MASK))) | ( \
      (uint32_t)(Reseed))) \
  )

/* ----------------------------------------------------------------------------
   -- SetFIFOUnderflow
   ---------------------------------------------------------------------------- */

/**
 * @brief Sets FIFO underflow response mode.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Mode Response mode. Use constants from group "FIFO Underflow response
 *        mode constants". This parameter is 2 bits wide.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: RNG_CR.
 * @par Example:
 *      @code
 *      RNG_PDD_SetFIFOUnderflow(<peripheral>_BASE_PTR, RNG_PDD_RET_ZERO);
 *      @endcode
 */
#define RNG_PDD_SetFIFOUnderflow(PeripheralBase, Mode) ( \
    RNG_CR_REG(PeripheralBase) = \
     (uint32_t)(( \
      (uint32_t)(RNG_CR_REG(PeripheralBase) & (uint32_t)(~(uint32_t)RNG_CR_FUFMOD_MASK))) | ( \
      (uint32_t)(Mode))) \
  )

/* ----------------------------------------------------------------------------
   -- GetFIFOUnderflow
   ---------------------------------------------------------------------------- */

/**
 * @brief Returns FIFO underflow response mode.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 32-bit value.
 * @remarks The macro accesses the following registers: RNG_CR.
 * @par Example:
 *      @code
 *      uint32_t result = RNG_PDD_GetFIFOUnderflow(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_GetFIFOUnderflow(PeripheralBase) ( \
    (uint32_t)(RNG_CR_REG(PeripheralBase) & RNG_CR_FUFMOD_MASK) \
  )

/* ----------------------------------------------------------------------------
   -- GetStatusRegister
   ---------------------------------------------------------------------------- */

/**
 * @brief Returns the content of the RNGB Status Register.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Use constants from group "Status of RNG" for processing return value.
 * @remarks The macro accesses the following registers: RNG_SR.
 * @par Example:
 *      @code
 *      uint32_t result = RNG_PDD_GetStatusRegister(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_GetStatusRegister(PeripheralBase) ( \
    RNG_SR_REG(PeripheralBase) \
  )

/* ----------------------------------------------------------------------------
   -- GetFIFOSize
   ---------------------------------------------------------------------------- */

/**
 * @brief Returns the FIFO size.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 4-bit value. The value is cast to "uint8_t".
 * @remarks The macro accesses the following registers: RNG_SR.
 * @par Example:
 *      @code
 *      uint8_t result = RNG_PDD_GetFIFOSize(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_GetFIFOSize(PeripheralBase) ( \
    (uint8_t)(( \
     (uint32_t)(RNG_SR_REG(PeripheralBase) & RNG_SR_FIFO_SIZE_MASK)) >> ( \
     RNG_SR_FIFO_SIZE_SHIFT)) \
  )

/* ----------------------------------------------------------------------------
   -- GetFIFOLevel
   ---------------------------------------------------------------------------- */

/**
 * @brief Returns FIFO level.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 4-bit value. The value is cast to "uint8_t".
 * @remarks The macro accesses the following registers: RNG_SR.
 * @par Example:
 *      @code
 *      uint8_t result = RNG_PDD_GetFIFOLevel(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_GetFIFOLevel(PeripheralBase) ( \
    (uint8_t)(( \
     (uint32_t)(RNG_SR_REG(PeripheralBase) & RNG_SR_FIFO_LVL_MASK)) >> ( \
     RNG_SR_FIFO_LVL_SHIFT)) \
  )

/* ----------------------------------------------------------------------------
   -- GetExtendedError
   ---------------------------------------------------------------------------- */

/**
 * @brief Returns the extended error from status register.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Use constants from group "Extended error mask for status register"
 *         for processing return value.
 * @remarks The macro accesses the following registers: RNG_SR.
 * @par Example:
 *      @code
 *      uint32_t result = RNG_PDD_GetExtendedError(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_GetExtendedError(PeripheralBase) ( \
    (uint32_t)(RNG_SR_REG(PeripheralBase) & (uint32_t)((uint32_t)0x7FFU << 21U)) \
  )

/* ----------------------------------------------------------------------------
   -- GetErrorStatusRegister
   ---------------------------------------------------------------------------- */

/**
 * @brief Returns the content of the RNGB Error Status Register.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Use constants from group "Error mask for error status register" for
 *         processing return value.
 * @remarks The macro accesses the following registers: RNG_ESR.
 * @par Example:
 *      @code
 *      uint32_t result = RNG_PDD_GetErrorStatusRegister(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_GetErrorStatusRegister(PeripheralBase) ( \
    RNG_ESR_REG(PeripheralBase) \
  )

/* ----------------------------------------------------------------------------
   -- GetOutValue
   ---------------------------------------------------------------------------- */

/**
 * @brief Returns the random data generated by the RNGB.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 32-bit value.
 * @remarks The macro accesses the following registers: RNG_OUT.
 * @par Example:
 *      @code
 *      uint32_t result = RNG_PDD_GetOutValue(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_GetOutValue(PeripheralBase) ( \
    RNG_OUT_REG(PeripheralBase) \
  )

/* ----------------------------------------------------------------------------
   -- ReseedNeeded
   ---------------------------------------------------------------------------- */

/**
 * @brief Returns 1 if manual reseeding is required.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 1-bit value. The value is cast to "uint8_t".
 * @remarks The macro accesses the following registers: RNG_SR.
 * @par Example:
 *      @code
 *      uint8_t result = RNG_PDD_ReseedNeeded(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define RNG_PDD_ReseedNeeded(PeripheralBase) ( \
    (uint8_t)((uint32_t)(RNG_SR_REG(PeripheralBase) & RNG_SR_RS_MASK) >> RNG_SR_RS_SHIFT) \
  )
#endif  /* #if defined(RNG_PDD_H_) */

/* RNG_PDD.h, eof. */
