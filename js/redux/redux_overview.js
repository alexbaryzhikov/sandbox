import { configureStore } from '@reduxjs/toolkit'

// State
const initialState = { value: 0 }

// Action creators
function increment() { return { type: 'counter/increment' } }
function decrement() { return { type: 'counter/decrement' } }

// Reducer
function counterReducer(state = initialState, action) {
    if (action.type === 'counter/increment') {
        return { value: state.value + 1 }
    } else if (action.type === 'counter/decrement') {
        return { value: state.value - 1 }
    }
    return state
}

// Store
const store = configureStore({ reducer: counterReducer })
console.log(store.getState())

// Dispatch
store.dispatch(increment())
console.log(store.getState())

store.dispatch(decrement())
console.log(store.getState())
