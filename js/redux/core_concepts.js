import { createStore } from 'redux'

var initialState = {
    todos: [
        {
            text: 'Eat food',
            completed: true
        },
        {
            text: 'Exercise',
            completed: false
        }
    ],
    visibilityFilter: 'SHOW_COMPLETED'
}

function todos(state = [], action) {
    switch (action.type) {
        case 'ADD_TODO':
            return state.concat([{ text: action.text, completed: false }])
        case 'TOGGLE_TODO':
            return state.map((todo, index) =>
                action.index === index
                    ? { text: todo.text, completed: !todo.completed }
                    : todo
            )
        default:
            return state
    }
}

function visibilityFilter(state = 'SHOW_ALL', action) {
    if (action.type === 'SET_VISIBILITY_FILTER') {
        return action.filter
    } else {
        return state
    }
}

function todoApp(state = initialState, action) {
    return {
        todos: todos(state.todos, action),
        visibilityFilter: visibilityFilter(state.visibilityFilter, action)
    }
}

let store = createStore(todoApp)
store.subscribe(() => console.log(store.getState()))


store.dispatch({ type: 'ADD_TODO', text: 'Go to swimming pool' })
store.dispatch({ type: 'TOGGLE_TODO', index: 1 })
store.dispatch({ type: 'SET_VISIBILITY_FILTER', filter: 'SHOW_ALL' })